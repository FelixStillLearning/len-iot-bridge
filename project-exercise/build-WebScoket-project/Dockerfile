# STAGE 1: The Builder Environment
FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

# Install dependencies dasar dan sertifikat agar bisa download lewat https
RUN apt-get update && apt-get install -y \
    build-essential \
    python3-pip \
    git \
    wget \
    pkg-config \
    apt-transport-https \
    ca-certificates \
    gnupg \
    lsb-release \
    && rm -rf /var/lib/apt/lists/*

# Menambahkan repository resmi Kitware untuk mendapatkan CMake versi terbaru (3.20+)
RUN wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor -o /usr/share/keyrings/kitware-archive-keyring.gpg \
    && echo "deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ $(lsb_release -cs) main" | tee /etc/apt/sources.list.d/kitware.list >/dev/null \
    && apt-get update \
    && apt-get install -y cmake \
    && rm -rf /var/lib/apt/lists/*

# Sisa Dockerfile (Conan dan Build) tetap sama
RUN pip3 install conan && conan profile detect --force

WORKDIR /app
COPY conanfile.txt .
RUN conan install . --output-folder=build --build=missing

COPY . .
RUN cmake --preset conan-release && cmake --build --preset conan-release

FROM ubuntu:22.04

RUN apt-get update && apt-get install -y \
    libstdc++6 \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app

COPY --from=builder /app/build/build/Release/iot_bridge .

EXPOSE 50051 9002

CMD ["./iot_bridge"]