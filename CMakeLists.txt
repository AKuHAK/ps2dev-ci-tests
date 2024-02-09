cmake_minimum_required(VERSION 3.20)
set(CMAKE_TOOLCHAIN_FILE $ENV{PS2SDK}/ps2dev.cmake)

project(tests)

set(HARNESS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(tests)
