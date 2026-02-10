FROM ubuntu:22.04 AS build

ENV DEBIAN_FRONTEND=noninteractive

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

WORKDIR /tmp
RUN wget https://github.com/Kitware/CMake/releases/download/v3.31.3/cmake-3.31.3-linux-x86_64.tar.gz -O cmake.tar.gz && \
    tar -xzf cmake.tar.gz && \
    mv cmake-3.31.3-linux-x86_64 /usr/local/cmake && \
    ln -s /usr/local/cmake/bin/* /usr/local/bin && \
    rm cmake.tar.gz

WORKDIR /opt
RUN wget https://github.com/OpenDDS/OpenDDS/releases/download/DDS-3.29.1/OpenDDS-3.29.1.tar.gz -O OpenDDS.tar.gz && \
    tar -xzf OpenDDS.tar.gz && \
    mv OpenDDS-3.29.1 OpenDDS && \
    rm OpenDDS.tar.gz

WORKDIR /opt/OpenDDS
RUN ./configure --java && \
    make -j$(nproc)

ENV DDS_ROOT=/opt/OpenDDS
ENV ACE_ROOT=/opt/OpenDDS/ACE_wrappers
ENV TAO_ROOT=/opt/OpenDDS/ACE_wrappers/TAO
ENV OPENDDS_INCLUDE_DIRS=$DDS_ROOT
ENV LD_LIBRARY_PATH=$DDS_ROOT/lib:$ACE_ROOT/lib:$TAO_ROOT/lib

WORKDIR /app
COPY . .

RUN rm -rf build && mkdir build && cd build && \
    cmake .. && \
    make -j$(nproc)

FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
    libssl-dev \
    openjdk-17-jre-headless \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /app/build
WORKDIR /app/build

COPY --from=build /opt/OpenDDS /opt/OpenDDS

COPY --from=build /app/build/publisher /app/build/publisher
COPY --from=build /app/build/subscriber /app/build/subscriber
COPY --from=build /app/rtps.ini /app/build/rtps.ini

ENV ACE_ROOT="/opt/OpenDDS/ACE_wrappers" \
    DDS_ROOT="/opt/OpenDDS" \
    TAO_ROOT="/opt/OpenDDS/ACE_wrappers/TAO" \
    JAVA_HOME="/usr/lib/jvm/java-17-openjdk-amd64" \
    JAVA_PLATFORM="linux" \
    LD_LIBRARY_PATH="/opt/OpenDDS/ACE_wrappers/lib:/opt/OpenDDS/lib:${LD_LIBRARY_PATH}" \
    PATH="/opt/OpenDDS/ACE_wrappers/bin:/opt/OpenDDS/bin:${PATH}"

RUN useradd -ms /bin/bash serviceuser && \
    chown serviceuser:serviceuser -R /app && \
    chmod -R 500 /app && \
    chmod -R 700 /app/build

USER serviceuser

CMD ["./subscriber", "-DCPSConfigFile", "rtps.ini"]