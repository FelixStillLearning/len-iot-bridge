FROM ubuntu:22.04 AS builder

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    build-essential \
    git \
    python3-pip \
    pkg-config \
    wget \
    cmake \
    curl \
    iproute2 \
    perl \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install conan && conan profile detect --force

WORKDIR /opt
RUN wget https://github.com/OpenDDS/OpenDDS/releases/download/DDS-3.29.1/OpenDDS-3.29.1.tar.gz -O OpenDDS.tar.gz && \
    tar -xzf OpenDDS.tar.gz && \
    mv OpenDDS-3.29.1 OpenDDS && \
    rm OpenDDS.tar.gz

WORKDIR /opt/OpenDDS
RUN ./configure --no-tests && \
    make -j$(nproc)

ENV DDS_ROOT=/opt/OpenDDS
ENV ACE_ROOT=/opt/OpenDDS/ACE_wrappers
ENV TAO_ROOT=/opt/OpenDDS/ACE_wrappers/TAO
ENV LD_LIBRARY_PATH=$DDS_ROOT/lib:$ACE_ROOT/lib:$TAO_ROOT/lib:$LD_LIBRARY_PATH

WORKDIR /tmp
RUN wget https://github.com/Kitware/CMake/releases/download/v3.31.0/cmake-3.31.0-linux-x86_64.tar.gz -O cmake.tar.gz && \
    tar -xzf cmake.tar.gz && \
    mv cmake-3.31.0-linux-x86_64 /opt/cmake-3.31.0 && \
    ln -sf /opt/cmake-3.31.0/bin/* /usr/local/bin/ && \
    rm -rf cmake.tar.gz

WORKDIR /app
COPY conanfile.txt .
RUN conan install . --output-folder=build --build=missing -s build_type=Release

COPY . .
ENV OPENDDS_DIR="/opt/OpenDDS"

RUN cmake --preset conan-release \
    -DCMAKE_MODULE_PATH="/opt/OpenDDS/cmake"

RUN cmake --build --preset conan-release

FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    libstdc++6 \
    libssl-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /app/bin

ENV DDS_ROOT="/opt/OpenDDS" \
    ACE_ROOT="/opt/OpenDDS/ACE_wrappers" \
    TAO_ROOT="/opt/OpenDDS/ACE_wrappers/TAO" \
    LD_LIBRARY_PATH="/opt/OpenDDS/lib:/opt/OpenDDS/ACE_wrappers/lib:${LD_LIBRARY_PATH}"

COPY --from=builder /opt/OpenDDS/lib /opt/OpenDDS/lib
COPY --from=builder /opt/OpenDDS/ACE_wrappers/lib /opt/OpenDDS/ACE_wrappers/lib

COPY --from=builder /app/build/build/Release /app/bin
EXPOSE 50051

CMD ["./grpc_gateway"]