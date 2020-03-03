cmake_minimum_required(VERSION 2.8)

project(module_tools_can_can_rx)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)

message(${SRCS})

include_directories(
  include
  ../../../communication/socket_can/include
  ../can_pack_unpack/include
  ../../../util/include
  ../../../tools/hlog/include
)

add_library(module_tools_can_can_rx ${SRCS})

target_link_libraries(module_tools_can_can_rx
  yaml-cpp
)
