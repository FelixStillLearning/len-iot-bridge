cmake_minimum_required(VERSION 3.31.0)
project(simple-project VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

include_directories()
link_directories()

file(GLOB_RECURSE SOURCES src/*.cpp src/*.cc src/*.h src/*.hpp)
list(REMOVE_ITEM SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp)
add_library(shared-objects OBJECT ${SOURCES})

add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/app.cpp $<TARGET_OBJECTS:shared-objects>)

find_package(Boost CONFIG)
target_link_libraries(${PROJECT_NAME} PRIVATE Boost::boost)
include_directories(${Boost_INCLUDE_DIR})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
