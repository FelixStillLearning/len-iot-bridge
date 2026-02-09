#include "SensorListener.h"
#include <iostream>

void SensorListener::on_data_available(DDS::DataReader_ptr reader) {
    try {
        SmartHome::ThermometerDataReader_var reader_i = SmartHome::ThermometerDataReader::_narrow(reader);
        if (!reader_i) return;

        SmartHome::Thermometer msg;
        DDS::SampleInfo info;

        while (reader_i->take_next_sample(msg, info) == DDS::RETCODE_OK) {
            if (info.valid_data) {
                std::cout << ">>> [MONITOR] Room: " << msg.room_id 
                          << " | Temp: " << msg.temperature 
                          << " | Status: " << msg.status << std::endl;
            }
        }
    } catch (const CORBA::Exception& e) {
        e._tao_print_exception("Exception in Listener:");
    }
}

// Empty implementations
void SensorListener::on_requested_deadline_missed(DDS::DataReader_ptr, const DDS::RequestedDeadlineMissedStatus&) {}
void SensorListener::on_requested_incompatible_qos(DDS::DataReader_ptr, const DDS::RequestedIncompatibleQosStatus&) {}
void SensorListener::on_sample_rejected(DDS::DataReader_ptr, const DDS::SampleRejectedStatus&) {}
void SensorListener::on_liveliness_changed(DDS::DataReader_ptr, const DDS::LivelinessChangedStatus&) {}
void SensorListener::on_subscription_matched(DDS::DataReader_ptr, const DDS::SubscriptionMatchedStatus&) {}
void SensorListener::on_sample_lost(DDS::DataReader_ptr, const DDS::SampleLostStatus&) {}