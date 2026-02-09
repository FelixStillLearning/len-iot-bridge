# ==========================================
# STAGE 1: BUILDER
# ==========================================
FROM ubuntu:22.04 AS build

ENV DEBIAN_FRONTEND=noninteractive

# 1. Install Build Dependencies (Termasuk Java JDK 17)
RUN apt-get update -y && \
    apt-get install -y --no-install-recommends \
        autoconf \
        bison \
        build-essential \
        ca-certificates \
        curl \
        flex \
        g++ \
        gcc \
        git \
        libssl-dev \
        pkg-config \
        python3 \
        python3-pip \
        tar \
        unzip \
        wget \
        zip \
        zlib1g-dev \
        openjdk-17-jdk \
    && rm -rf /var/lib/apt/lists/*

# 2. Install CMake 3.31.3 (Manual Download)
WORKDIR /tmp
RUN wget https://github.com/Kitware/CMake/releases/download/v3.31.3/cmake-3.31.3-linux-x86_64.tar.gz -O cmake.tar.gz && \
    tar -xzf cmake.tar.gz && \
    mv cmake-3.31.3-linux-x86_64 /usr/local/cmake && \
    ln -s /usr/local/cmake/bin/* /usr/local/bin && \
    rm cmake.tar.gz

# 3. Install & Compile OpenDDS 3.29.1
WORKDIR /opt
RUN wget https://github.com/OpenDDS/OpenDDS/releases/download/DDS-3.29.1/OpenDDS-3.29.1.tar.gz -O OpenDDS.tar.gz && \
    tar -xzf OpenDDS.tar.gz && \
    mv OpenDDS-3.29.1 OpenDDS && \
    rm OpenDDS.tar.gz

# Compile OpenDDS (Support Java)
WORKDIR /opt/OpenDDS
RUN ./configure --java && \
    make -j$(nproc)

# 4. Set Environment Variables untuk Build Process
ENV DDS_ROOT=/opt/OpenDDS
ENV ACE_ROOT=/opt/OpenDDS/ACE_wrappers
ENV TAO_ROOT=/opt/OpenDDS/ACE_wrappers/TAO
ENV OPENDDS_INCLUDE_DIRS=$DDS_ROOT
ENV LD_LIBRARY_PATH=$DDS_ROOT/lib:$ACE_ROOT/lib:$TAO_ROOT/lib

# 5. Build Project Smart Home
WORKDIR /app
COPY . .

# Compile Project C++
RUN rm -rf build && mkdir build && cd build && \
    cmake .. && \
    make -j$(nproc)

# ==========================================
# STAGE 2: RUNTIME
# ==========================================
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# 1. Install Runtime Dependencies (Hanya JRE)
RUN apt-get update && apt-get install -y --no-install-recommends \
    libssl-dev \
    openjdk-17-jre-headless \
    && rm -rf /var/lib/apt/lists/*

# 2. Setup Folder Aplikasi
RUN mkdir -p /app/build
WORKDIR /app/build

# 3. Copy Library OpenDDS dari Stage Build
COPY --from=build /opt/OpenDDS /opt/OpenDDS

# 4. Copy Hasil Build Aplikasi & Config
# Pastikan file binary ada di folder /app/build di container
COPY --from=build /app/build/publisher /app/build/publisher
COPY --from=build /app/build/subscriber /app/build/subscriber
COPY --from=build /app/rtps.ini /app/build/rtps.ini

# 5. Set Environment Variables Runtime
ENV ACE_ROOT="/opt/OpenDDS/ACE_wrappers" \
    DDS_ROOT="/opt/OpenDDS" \
    TAO_ROOT="/opt/OpenDDS/ACE_wrappers/TAO" \
    JAVA_HOME="/usr/lib/jvm/java-17-openjdk-amd64" \
    JAVA_PLATFORM="linux" \
    LD_LIBRARY_PATH="/opt/OpenDDS/ACE_wrappers/lib:/opt/OpenDDS/lib:${LD_LIBRARY_PATH}" \
    PATH="/opt/OpenDDS/ACE_wrappers/bin:/opt/OpenDDS/bin:${PATH}"

# 6. Create Non-Root User (Service User)
RUN useradd -ms /bin/bash serviceuser && \
    chown serviceuser:serviceuser -R /app && \
    chmod -R 500 /app && \
    chmod -R 700 /app/build

# Switch User
USER serviceuser

# Default Command (Subscriber)
CMD ["./subscriber", "-DCPSConfigFile", "rtps.ini"]