# OpenDDS Pub/Sub (C++)

A simple OpenDDS demo with a publisher (sensor) and a subscriber (monitor). It uses RTPS discovery to run brokerless.

Author: Felix Angga Resky

## Architecture

- Data contract: idl/SensorData.idl
- Publisher: src/publisher.cpp
- Subscriber: src/subscriber.cpp
- Listener: src/SensorListener.h, src/SensorListener.cpp
- Discovery: rtps.ini

## Prerequisites

Docker workflow:
- Docker Engine
- Docker Compose

Local workflow:
- CMake 3.10+
- C++17 compiler
- OpenDDS 3.29.1 (or compatible)

## Docker Workflow

```bash
sudo docker compose up --build
```

This starts two services:
- monitor (subscriber)
- sensor (publisher)

## Local Workflow

```bash
mkdir -p build && cd build
cmake ..
make -j$(nproc)
./subscriber -DCPSConfigFile ../rtps.ini
```

In a second terminal:

```bash
cd build
./publisher -DCPSConfigFile ../rtps.ini
```

## Notes

- Domain ID used in code is 42 for both publisher and subscriber.
- RTPS discovery allows peer-to-peer discovery without a central repo.

## Reference

Part 3 (OpenDDS pub/sub):
https://medium.com/@felixangga077/tech-exploration-part-3-implementing-a-real-time-pub-sub-architecture-using-opendds-fa1dabaaa937
