cmake_minimum_required(VERSION 2.8)

project(module_communication_udp)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)

message(${SRCS})

include_directories(
  ../../common/include
  include
)

add_library(module_communication_udp ${SRCS})

add_executable(example_udp example/src/main.cpp)

add_dependencies(example_udp
  module_communication_udp
)

target_link_libraries(example_udp
  module_communication_udp
)
