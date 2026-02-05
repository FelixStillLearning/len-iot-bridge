# Ubah ownership folder ke user
sudo chown -R felixrdev:felixrdev ~/workspace/len-iot-bridge/

# Atau dari dalam folder
cd ~/workspace/len-iot-bridge/CPP_OOP
sudo chown -R felixrdev:felixrdev .

# Compile
g++ -o classnobject Classnobject.cpp

# Run
./classnobject

---

# Docker Compose (cpp-simple-project-main)
cd ~/workspace/len-iot-bridge/cpp-simple-project-main

# Build image
sudo docker compose build

# External network harus ada (sekali saja)
sudo docker network create cms_network

# Run container
sudo docker compose up -d

# Cek status
sudo docker compose ps

# Lihat log
sudo docker compose logs -f simple-project

# Stop
sudo docker compose down

---

# generate_proto (simple-grpc-cpp)
cd ~/workspace/len-iot-bridge/project-example/simple-grpc-cpp

# Install dependency
sudo apt update
sudo apt install -y protobuf-compiler protobuf-compiler-grpc

# Install script ke /usr/local/bin
sudo install -m 755 ./generate_proto /usr/local/bin/generate_proto

# Cari file proto
find ~/workspace/len-iot-bridge -name "*.proto"

# Run (contoh)
generate_proto proto/test_data