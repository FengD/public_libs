cmake_minimum_required(VERSION 2.8)

project(library)

add_subdirectory(module/communication/tcp)
add_subdirectory(module/communication/udp)
add_subdirectory(module/our_thread)
add_subdirectory(module/util)
