#include "grpc_server.h"
#include "ws_server.h"
#include "Sensor.grpc.pb.h"
#include <grpcpp/grpcpp.h>
#include <iostream>
#include <rapidjson/document.h>
#include <rapidjson/stringbuffer.h>
#include <rapidjson/writer.h>

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using iotbridge::SensorService;
using iotbridge::TemperatureRequest;
using iotbridge::TemperatureResponse;

class SensorServiceImpl final : public SensorService::Service {
    Status SendTemperature(ServerContext* context, const TemperatureRequest* request, TemperatureResponse* reply) override {
        std::cout  << "[gRPC] Accepting temperature data from: " << request->room_id() << std::endl;
        rapidjson::StringBuffer buffer;
        rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);

        writer.StartObject();
        writer.Key("room_id");
        writer.String(request->room_id().c_str());
        writer.Key("temperature");
        writer.Double(request->temperature());
        writer.Key("status");
        writer.String(request->status().c_str());
        writer.EndObject();

        std::string json_payload = buffer.GetString();

        broadcast_ws_message(json_payload);

        reply->set_success(true);
        reply->set_message("data has been successfully broadcast to dashboard");
        return Status::OK;
    }
};

void start_grpc_server(int port) {
    std::string server_address("0.0.0.0:" + std::to_string(port));
    SensorServiceImpl service;
    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);

    std::unique_ptr<Server>  server(builder.BuildAndStart());
    std::cout << "gRPC Server listening on " << server_address << std::endl;
    server->Wait();
}