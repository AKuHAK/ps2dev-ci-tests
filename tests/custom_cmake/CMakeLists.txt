
add_executable(custom_cmake.elf main.cpp)
# Ensure you include HARNESS_INCLUDE_DIR
target_include_directories(custom_cmake.elf PUBLIC ${HARNESS_INCLUDE_DIR})
target_link_libraries(custom_cmake.elf -lkernel -lps2_drivers -lpatches)
