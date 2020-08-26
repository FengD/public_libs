cmake_minimum_required(VERSION 2.8)

project(module_communication_share_memory)

add_definitions(-std=c++14 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++14 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)

message(${SRCS})

include_directories(
  ../../common/include
  include
  /usr/include/pcl-1.10/
  /usr/include/eigen3/
)

add_library(module_communication_share_memory ${SRCS})

add_executable(share_memory_example_posix example_posix/src/main.cpp)

add_dependencies(share_memory_example_posix
  module_communication_share_memory
)

target_link_libraries(share_memory_example_posix
  module_communication_share_memory
  pthread
  rt
  pcl_common
)

add_executable(share_memory_example_c example_c/src/main.cpp)

add_dependencies(share_memory_example_c
  module_communication_share_memory
)

target_link_libraries(share_memory_example_c
  module_communication_share_memory
  pcl_common
)
