cmake_minimum_required(VERSION 3.10)
project(SmartHome_OpenDDS)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenDDS REQUIRED)

add_library(idl_lib idl/SensorData.idl)

OPENDDS_TARGET_SOURCES(idl_lib idl/SensorData.idl)

target_include_directories(idl_lib PUBLIC 
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}/opendds_generated
    ${CMAKE_CURRENT_SOURCE_DIR}/idl
    ${OPENDDS_INCLUDE_DIRS}
)

target_link_libraries(idl_lib OpenDDS::Dcps)

add_executable(publisher src/publisher.cpp)
target_link_libraries(publisher idl_lib OpenDDS::Dcps)

add_executable(subscriber src/subscriber.cpp src/SensorListener.cpp)
target_link_libraries(subscriber idl_lib OpenDDS::Dcps)