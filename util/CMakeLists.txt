cmake_minimum_required(VERSION 2.8)

project(module_util)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)

message(${SRCS})

include_directories(
  ../../common/include
  include
)

add_library(module_util ${SRCS})
