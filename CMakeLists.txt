cmake_minimum_required(VERSION 2.8)

project(library)

add_subdirectory(communication/tcp)
add_subdirectory(communication/udp)
add_subdirectory(communication/socket_can)
add_subdirectory(our_thread)
add_subdirectory(util)
add_subdirectory(tools/can/can_rx)
add_subdirectory(tools/can/can_tx)
add_subdirectory(tools/can/can_pack_unpack)
add_subdirectory(tools/hlog)
add_subdirectory(tools/memory_check)
