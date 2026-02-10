#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "Sensor.grpc.pb.h"


using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using iotbridge::SensorService;
using iotbridge::TemperatureRequest;
using iotbridge::TemperatureResponse;

class SensorServiceImpl final : public SensorService::Service {
    
     Status SendTemperature(ServerContext* context, const TemperatureRequest* request,
                           TemperatureResponse* reply) override {
        
        std::cout << "[gRPC Gateway] Accepting Data :" << std::endl;
        std::cout << "  Room : " << request->room_id() << std::endl;
        std::cout << "  Temperature  : " << request->temperature() << " C" << std::endl;
        std::cout << "  Status  : " << request->status() << std::endl;

        reply->set_success(true);
        std::string msg = "Data accepted by Gateway";
        reply->set_message(msg);

        return Status::OK; 
    }
};


void RunServer() {
    std::string server_address("0.0.0.0:50051"); 
    SensorServiceImpl service;

    ServerBuilder builder;
    
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    
    builder.RegisterService(&service);
    
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server gRPC listen in " << server_address << std::endl;

    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}