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

add_custom_target(run_tests)

FOREACH(TEST ${TESTS})
  # Check for a custom cmakelist
  if(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${TEST}/CMakeLists.txt)
    message(STATUS "Adding test (custom build cfg): ${TEST}")
    add_subdirectory(${TEST})
    # Debating on whether to include the harness here or let the test include it

  # If no custom cmakelist, check for a .c file
  # Create the executable and link the necessities
  elseif(EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${TEST}/${TEST}.c)
    message(STATUS "Adding test: ${TEST}")
    add_executable(${TEST}.elf ${TEST}/${TEST}.c)
    target_link_libraries(${TEST}.elf -lkernel -lps2_drivers -lpatches)
    target_include_directories(${TEST}.elf PUBLIC ${HARNESS_INCLUDE_DIR})
    # Not that pretty, I would like to have the generated CMakeFiles in the same directory as the test
    # I need to fake add_subdirectory, or force each test to have a CMakeLists.txt
    set_target_properties(${TEST}.elf PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/tests/${TEST}")
  else()
    message(WARNING "No test found in ${TEST}")
  endif()

  configure_file(${CMAKE_CURRENT_SOURCE_DIR}/test.cmake.in ${CMAKE_CURRENT_BINARY_DIR}/test_${TEST}.cmake @ONLY)
  add_custom_command(TARGET run_tests COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/test_${TEST}.cmake)
ENDFOREACH()





