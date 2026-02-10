# gRPC Gateway (C++)

A minimal gRPC server that receives temperature data and prints it to stdout. This project demonstrates a modern C++ build workflow with Conan, CMake presets, and Docker.

Author: Felix Angga Resky

## Architecture

- Protocol: gRPC + Protobuf
- Contract: proto/Sensor.proto
- Server implementation: src/grpc_server.cpp
- Generated code: build/proto_gen (created at configure/build time)

## Prerequisites

Docker workflow:
- Docker Engine
- Docker Compose

Local workflow:
- CMake 3.15+
- C++17 compiler
- Conan

## Docker Workflow

```bash
sudo docker compose up --build
```

The server listens on port 50051.

## Local Workflow

```bash
conan install . --output-folder=build --build=missing
cmake --preset conan-release
cmake --build --preset conan-release
./build/Release/grpc_gateway
```

## Troubleshooting

- protoc not found: ensure protobuf compiler is available in the build image or host.
- If presets are missing, delete build/ and re-run conan install.

## Reference

Part 4 (gRPC + Protobuf):
https://medium.com/@felixangga077/tech-exploration-part-4-high-performance-communication-grpc-protobuf-3438042bbf4b?postPublishedType=initial
