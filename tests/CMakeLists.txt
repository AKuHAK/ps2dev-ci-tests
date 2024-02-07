cmake_minimum_required(VERSION 3.20)

set(CMAKE_TOOLCHAIN_FILE $ENV{PS2SDK}/ps2dev.cmake)

project(tests)

set(TEST_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

MACRO(SUBDIRLIST result curdir)
  FILE(GLOB children RELATIVE ${curdir} ${curdir}/*)
  SET(dirlist "")
  FOREACH(child ${children})
    IF(IS_DIRECTORY ${curdir}/${child})
      LIST(APPEND dirlist ${child})
    ENDIF()
  ENDFOREACH()
  SET(${result} ${dirlist})
ENDMACRO()

SUBDIRLIST(TESTS ${CMAKE_CURRENT_SOURCE_DIR})


FOREACH(TEST ${TESTS})
	message(STATUS "Adding test: ${TEST}")
	add_executable(${TEST}.elf ${TEST}/${TEST}.c)
  target_link_libraries(${TEST}.elf -lkernel -lps2_drivers -lpatches)
ENDFOREACH()

add_custom_target(run_tests)

foreach(TEST ${TESTS})
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/test_${TEST}.cmake @ONLY)
    add_custom_command(TARGET run_tests COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/test_${TEST}.cmake)
endforeach()


