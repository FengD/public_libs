cmake_minimum_required(VERSION 2.8)

project(module_our_thread)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)

message(${SRCS})

include_directories(
  ../common/include
  include
  ../util/include
  ../tools/hlog/include
)

add_library(module_our_thread ${SRCS})

target_link_libraries(module_our_thread
  yaml-cpp
  pthread
  module_tools_hlog
)

add_executable(base_example example/thread_base_demo/src/demo.cpp)

add_dependencies(base_example
  module_our_thread
)

target_link_libraries(base_example
  module_our_thread
  pthread
  yaml-cpp
)

add_executable(period_example example/thread_period_demo/src/demo.cpp)

add_dependencies(period_example
  module_our_thread
)

target_link_libraries(period_example
  module_our_thread
  pthread
  yaml-cpp
)

add_executable(multi_thread_demo example/multi_thread_demo/src/demo.cpp)

add_dependencies(multi_thread_demo
  module_our_thread
)

target_link_libraries(multi_thread_demo
  module_our_thread
  pthread
  yaml-cpp
)
