cmake_minimum_required(VERSION 2.8)

project(module_communication_socket_can)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)

message(${SRCS})

include_directories(
  ../../common/include
  include
  ../../tools/hlog/include
)

add_library(module_communication_socket_can ${SRCS})
