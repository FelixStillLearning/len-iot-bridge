# Project Exercise

This folder contains two focused C++ exercises that demonstrate a local workflow and a Docker workflow.

Author: Felix Angga Resky

## Projects

1) build-gRPC-Project
- Purpose: gRPC server gateway that accepts temperature data over HTTP/2.
- Protocol: Protobuf + gRPC.

2) build-opendds-project
- Purpose: OpenDDS pub/sub demo with a publisher (sensor) and a subscriber (monitor).
- Protocol: DDS (OpenDDS).

## Prerequisites

For Docker workflow:
- Docker Engine
- Docker Compose

For local workflow:
- CMake 3.15+
- C++17 compiler
- Conan
- OpenDDS (only for build-opendds-project)

## Quickstart (Docker)

### gRPC gateway

```bash
cd build-gRPC-Project
sudo docker compose up --build
```

### OpenDDS pub/sub

```bash
cd build-opendds-project
sudo docker compose up --build
```

## Quickstart (Local)

### gRPC gateway

```bash
cd build-gRPC-Project
conan install . --output-folder=build --build=missing
cmake --preset conan-release
cmake --build --preset conan-release
./build/Release/grpc_gateway
```

### OpenDDS pub/sub

```bash
cd build-opendds-project
mkdir -p build && cd build
cmake ..
make -j$(nproc)
./subscriber -DCPSConfigFile ../rtps.ini
```

In a second terminal:

```bash
cd build-opendds-project/build
./publisher -DCPSConfigFile ../rtps.ini
```

## Notes

- The OpenDDS example uses RTPS discovery via rtps.ini and runs brokerless.
- The gRPC server listens on port 50051.

## Medium Series

- Part 1: WSL 2 + C++ toolchain setup
	https://medium.com/@felixangga077/eksplorasi-tech-membangun-lingkungan-development-c-profesional-menggunakan-wsl-2-572d503b8610
- Part 2: Modern C++ project structure + local vs Docker workflow
	https://medium.com/@felixangga077/eksplorasi-tech-part-2-membedah-struktur-project-c-modern-eksekusi-workflow-local-vs-docker-dba7222bea69
- Part 3: OpenDDS pub/sub implementation
	https://medium.com/@felixangga077/tech-exploration-part-3-implementing-a-real-time-pub-sub-architecture-using-opendds-fa1dabaaa937
- Part 4: gRPC + Protobuf
	https://medium.com/@felixangga077/tech-exploration-part-4-high-performance-communication-grpc-protobuf-3438042bbf4b?postPublishedType=initial
