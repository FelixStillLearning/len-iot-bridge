cmake_minimum_required(VERSION 3.15)
project(IoT_gRPC_Gateway C CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(gRPC REQUIRED)
find_package(Protobuf REQUIRED)
find_package(websocketpp REQUIRED)
find_package(RapidJSON REQUIRED)

set(PROTO_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/proto")
set(PROTO_BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/proto_gen")
file(MAKE_DIRECTORY ${PROTO_BINARY_DIR})
set(GRPC_CPP_PLUGIN_EXECUTABLE $<TARGET_FILE:gRPC::grpc_cpp_plugin>)
if(TARGET protobuf::protoc)
    set(PROTOC_EXECUTABLE $<TARGET_FILE:protobuf::protoc>)
else()
    set(PROTOC_EXECUTABLE ${Protobuf_PROTOC_EXECUTABLE})
endif()

add_custom_command(
    OUTPUT "${PROTO_BINARY_DIR}/Sensor.grpc.pb.cc"
           "${PROTO_BINARY_DIR}/Sensor.grpc.pb.h"
           "${PROTO_BINARY_DIR}/Sensor.pb.cc"
           "${PROTO_BINARY_DIR}/Sensor.pb.h"
    COMMAND ${PROTOC_EXECUTABLE}
    ARGS --grpc_out="${PROTO_BINARY_DIR}"
         --cpp_out="${PROTO_BINARY_DIR}"
         -I "${PROTO_SRC_DIR}"
         --plugin=protoc-gen-grpc=${GRPC_CPP_PLUGIN_EXECUTABLE}
         "${PROTO_SRC_DIR}/Sensor.proto"
    DEPENDS "${PROTO_SRC_DIR}/Sensor.proto"
)

add_executable(grpc_gateway
    src/grpc_server.cpp
    "${PROTO_BINARY_DIR}/Sensor.grpc.pb.cc"
    "${PROTO_BINARY_DIR}/Sensor.pb.cc"
)

target_include_directories(grpc_gateway PRIVATE
    "${PROTO_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
)

target_link_libraries(grpc_gateway
    gRPC::grpc++
    protobuf::libprotobuf
    websocketpp::websocketpp
    rapidjson
)