cmake_minimum_required(VERSION 3.10)
project(SmartHome_OpenDDS)

set(CMAKE_CXX_STANDARD 17)

# Find OpenDDS
find_package(OpenDDS REQUIRED)

# --- BAGIAN INI YANG DIPERBAIKI ---

# 1. Buat dulu wadah library-nya (add_library)
# Kita masukkan file .idl sebagai dummy source awal
add_library(idl_lib idl/SensorData.idl)

# 2. Baru panggil Macro OpenDDS untuk generate code & inject ke library tadi
OPENDDS_TARGET_SOURCES(idl_lib idl/SensorData.idl)

# 3. Setup Include Directories agar file .h hasil generate bisa ditemukan

target_include_directories(idl_lib PUBLIC 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/opendds_generated  # <--- TAMBAHKAN INI
    ${CMAKE_CURRENT_SOURCE_DIR}/idl
    ${OPENDDS_INCLUDE_DIRS}
)


# 4. Link library ini ke Core OpenDDS
target_link_libraries(idl_lib OpenDDS::Dcps)

# ----------------------------------

# Build Publisher
add_executable(publisher src/publisher.cpp)
target_link_libraries(publisher idl_lib OpenDDS::Dcps)

# Build Subscriber
add_executable(subscriber src/subscriber.cpp src/SensorListener.cpp)
target_link_libraries(subscriber idl_lib OpenDDS::Dcps)