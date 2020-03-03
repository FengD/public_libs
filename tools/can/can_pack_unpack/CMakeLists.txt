cmake_minimum_required(VERSION 2.8)

project(module_tools_can_can_pack_unpack)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)

message(${SRCS})

include_directories(
  include
  ../../../util/include
)

add_library(module_tools_can_can_pack_unpack ${SRCS})
