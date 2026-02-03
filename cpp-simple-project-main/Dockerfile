# ===== BUILD STAGE =====
FROM ubuntu:22.04 AS build

ENV DEBIAN_FRONTEND=noninteractive

# Install build dependencies with minimal packages
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
        zlib1g-dev && \
    rm -rf /var/lib/apt/lists/*

# Set a dedicated working directory for your application
WORKDIR /app

# Copy only configuration files first to leverage Docker layer caching
COPY ./docker/CMakeLists.txt /app/CMakeLists.txt
COPY ./conanfile.txt /app/conanfile.txt

# Install and configure Conan
RUN pip3 install --no-cache-dir conan && \
   conan profile detect --force && \
   conan install . --output-folder=build --build=missing

# Now copy the rest of your application source and ancillary files
COPY ./src /app/src
COPY ./simple.ior /app/
COPY ./rtps.ini /app/

# Configure the project using CMake presets (cached unless configuration files change)
RUN cmake --preset conan-release

# Build the project using parallelism
RUN cmake --build "/app/build" --config Release --target all -j$(nproc)

# ===== RUNTIME STAGE =====
FROM ubuntu:22.04

# Create the /app directory
RUN mkdir -p /app/build/logs

WORKDIR /app/build

# Copy files from the build stage
COPY --from=build /app/build/simple-project /app/build/simple-project
COPY --from=build /app/rtps.ini /app/rtps.ini
COPY --from=build /app/simple.ior /app/simple.ior

# Set environment variables for OpenDDS and Java
ENV ACE_ROOT="/opt/OpenDDS/ACE_wrappers" \
   DDS_ROOT="/opt/OpenDDS" \
   JAVA_HOME="/usr/lib/jvm/java-17-openjdk-amd64" \
   JAVA_PLATFORM="linux" \
   LD_LIBRARY_PATH="/opt/OpenDDS/ACE_wrappers/lib:/opt/OpenDDS/lib:${LD_LIBRARY_PATH}" \
   MPC_ROOT="/opt/OpenDDS/ACE_wrappers/MPC" \
   PATH="/opt/OpenDDS/ACE_wrappers/bin:/opt/OpenDDS/bin:${PATH}" \
   RAPIDJSON_ROOT="/opt/OpenDDS/tools/rapidjson"

# Create a non-root user for running the application and set permissions to the application directory
RUN useradd -ms /bin/bash serviceuser && \
    chown serviceuser:serviceuser -R /app && \
    chmod -R 500 /app && \
    chmod -R 700 /app/build/logs

# Switch to the non-root user for improved security
USER serviceuser

# Run the app
CMD ["./simple-project"]
