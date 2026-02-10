#include <iostream>
#include <thread>
#include "SensorListener.h"
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/SubscriberImpl.h>

int main(int argc, char* argv[]) {
    try {
        auto dpf = TheParticipantFactoryWithArgs(argc, argv);
        auto participant = dpf->create_participant(42, PARTICIPANT_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        SmartHome::ThermometerTypeSupport_var ts = new SmartHome::ThermometerTypeSupportImpl;
        ts->register_type(participant, "");
        
        CORBA::String_var type_name = ts->get_type_name();
        auto topic = participant->create_topic("RoomTemperature", type_name, TOPIC_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        auto sub = participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT, 0, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        DDS::DataReaderListener_var listener(new SensorListener);
        auto reader = sub->create_datareader(topic, DATAREADER_QOS_DEFAULT, listener, OpenDDS::DCPS::DEFAULT_STATUS_MASK);

        std::cout << "[Monitor] System Online. Waiting..." << std::endl;
        while (true) std::this_thread::sleep_for(std::chrono::seconds(1));

    } catch (const CORBA::Exception& e) {
        e._tao_print_exception("Exception in Subscriber:");
        return 1;
    }
    return 0;
}