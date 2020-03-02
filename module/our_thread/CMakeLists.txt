cmake_minimum_required(VERSION 2.8)

project(module_our_thread)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)

message(${SRCS})

include_directories(
  ../../common/include
  include
  ../../util/include/
)

add_library(module_our_thread ${SRCS})

target_link_libraries(module_our_thread
  yaml-cpp
  pthread
)
