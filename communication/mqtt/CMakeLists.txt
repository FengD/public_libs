cmake_minimum_required(VERSION 2.8)

project(module_communication_mqtt)

add_definitions(-std=c++11 -fPIC)
set(CMAKE_CXX_FLAGS "-std=c++11 -fPIC")
set(CMAKE_BUILD_TYPE "Release")

aux_source_directory(src SRCS)

message(${SRCS})

include_directories(
  ../../common/include
  include
  /home/ding/Documents/mosquitto/lib/
)

add_library(module_communication_mqtt ${SRCS})

add_executable(mqtt_sub_example example/sub/src/demo.cpp)

add_dependencies(mqtt_sub_example
  module_communication_mqtt
)

target_link_libraries(mqtt_sub_example
  module_communication_mqtt
  /home/ding/Documents/mosquitto/lib/libmosquitto.so.1
)

add_executable(mqtt_pub_example example/pub/src/demo.cpp)

add_dependencies(mqtt_pub_example
  module_communication_mqtt
)

target_link_libraries(mqtt_pub_example
  module_communication_mqtt
  /home/ding/Documents/mosquitto/lib/libmosquitto.so.1
)
