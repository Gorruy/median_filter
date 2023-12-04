cmake_minimum_required(VERSION 3.6)

project(median_filter)

set(CC gcc)

set(CMAKE_C_FLAGS "-Wall -O2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")

file(GLOB SOURCES "src/*.c")

add_executable(median_filter ${SOURCES})
