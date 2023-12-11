cmake_minimum_required(VERSION 3.5) 
project(median_filter)


file(GLOB SOURCES "src/*.c")

set(CMAKE_C_FLAGS "-Wall -O2")

option(BUILD_TESTS OFF)

if (BUILD_TESTS)
    set(COV_FLAGS "-fprofile-arcs -ftest-coverage -Wall -O2 -fprofile-arcs -fprofile-generate -lgcov --coverage")

    enable_testing()
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build/")
    link_libraries(gcov)
    enable_testing()

    set_source_files_properties(../src/median_filter.c PROPERTIES COMPILE_FLAGS ${COV_FLAGS})
    set_source_files_properties(../src/main.c PROPERTIES COMPILE_FLAGS ${COV_FLAGS})

    file(GLOB TEST "tests/*.c")

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

    add_executable(test_main 
        ${PROJECT_SOURCE_DIR}/tests/test_main.c 
        ${PROJECT_SOURCE_DIR}/src/median_filter.c)
    find_program (MAIN_TEST ${PROJECT_SOURCE_DIR}/tests/test.sh)
    add_test(
        "MainTest"
        ${MAIN_TEST}
        ${PROJECT_SOURCE_DIR}/tests/test.sh)

    add_executable(test_print 
        ${PROJECT_SOURCE_DIR}/tests/test_print_bin.c 
        ${PROJECT_SOURCE_DIR}/src/median_filter.c)
    find_program (PRINT_TEST ${PROJECT_SOURCE_DIR}/tests/test_print_bin.sh)
    add_test(
        "PrintBinTest"
        ${PRINT_TEST}
        ${PROJECT_SOURCE_DIR}/tests/test_print_bin.sh)

endif(BUILD_TESTS)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../bin/")

add_executable(median_filter ${SOURCES})

include(CTest)
