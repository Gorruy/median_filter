cmake_minimum_required(VERSION 2.8.10) 
project(median_filter)

enable_testing()

file(GLOB TEST "tests/*.c")

file(GLOB SOURCES "src/*.c")

add_executable(test_partition 
    ${PROJECT_SOURCE_DIR}/tests/test_partition.c 
    ${PROJECT_SOURCE_DIR}/src/median_filter.c)
add_test(
    "PartitionTest"
    ${PROJECT_SOURCE_DIR}/build/test_partition)

add_executable(test_k_order 
    ${PROJECT_SOURCE_DIR}/tests/test_k_order.c 
    ${PROJECT_SOURCE_DIR}/src/median_filter.c)
add_test(
    "KOrderTest"
    ${PROJECT_SOURCE_DIR}/build/test_k_order)

find_program (MAIN_TEST ${PROJECT_SOURCE_DIR}/tests/test.sh)
add_test(
    "MainTest"
    ${MAIN_TEST}
    ${PROJECT_SOURCE_DIR}/tests/test.sh)

find_program (PRINT_TEST ${PROJECT_SOURCE_DIR}/tests/test_print_bin.sh)
add_test(
    "PrintBinTest"
    ${PRINT_TEST}
    ${PROJECT_SOURCE_DIR}/tests/test_print_bin.sh)

set(CMAKE_C_FLAGS "-Wall -O2")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")

add_executable(median_filter ${SOURCES})

