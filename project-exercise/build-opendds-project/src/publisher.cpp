#include <iostream>
#include <thread>
#include <chrono>
#include "SensorDataTypeSupportImpl.h" 
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/PublisherImpl.h>

int main(int argc, char* argv[]) {
    try {
        auto dpf = TheParticipantFactoryWithArgs(argc, argv);
        auto participant = dpf->create_participant(42, PARTICIPANT_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        SmartHome::ThermometerTypeSupport_var ts = new SmartHome::ThermometerTypeSupportImpl;
        ts->register_type(participant, "");

        CORBA::String_var type_name = ts->get_type_name();
        auto topic = participant->create_topic("RoomTemperature", type_name, TOPIC_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        auto pub = participant->create_publisher(PUBLISHER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
        auto writer = pub->create_datawriter(topic, DATAWRITER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);
        
        SmartHome::ThermometerDataWriter_var sensor_writer = SmartHome::ThermometerDataWriter::_narrow(writer);

        SmartHome::Thermometer data;
        data.room_id = "Server Room 01";
        data.temperature = 25.0;
        data.status = "Normal";

        while (true) {
            data.temperature += 0.5;
            if (data.temperature > 30.0) data.status = "OVERHEAT WARNING";

            sensor_writer->write(data, DDS::HANDLE_NIL);
            std::cout << "[Sensor] Sent: " << data.temperature << " C | Status: " << data.status << std::endl;

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    } catch (const CORBA::Exception& e) {
        e._tao_print_exception("Exception in Publisher:");
        return 1;
    }
    return 0;
}