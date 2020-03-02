cmake_minimum_required(VERSION 2.8)

project(library)

add_subdirectory(communication/tcp)
add_subdirectory(communication/udp)
add_subdirectory(our_thread)
add_subdirectory(util)
