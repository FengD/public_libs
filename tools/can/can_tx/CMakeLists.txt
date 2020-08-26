cmake_minimum_required(VERSION 2.8)

project(module_tools_can_can_tx)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)
aux_source_directory(../../../communication/socket_can/src SRCS)
aux_source_directory(../can_pack_unpack/src SRCS)
aux_source_directory(../../../util/src SRCS)
aux_source_directory(../../../tools/hlog/src SRCS)

message(${SRCS})

include_directories(
  include
  ../../../communication/socket_can/include
  ../can_pack_unpack/include
  ../../../util/include
  ../../../tools/hlog/include
  ../../../common/include
)

add_library(module_tools_can_can_tx ${SRCS})

target_link_libraries(module_tools_can_can_tx
  yaml-cpp
)

add_executable(cantx_example example/src/main.cpp)

add_dependencies(cantx_example
  module_tools_can_can_tx
)

target_link_libraries(cantx_example
  module_tools_can_can_tx
  glog
)
