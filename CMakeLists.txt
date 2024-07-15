cmake_minimum_required(VERSION 3.5)

project(Chess_Cpp)

# include(${CMAKE_BINARY_DIR}/conan_paths.cmake)

# Modules

add_subdirectory("modules/chess")
add_subdirectory("modules/board")
add_subdirectory("modules/display")

# Samples
add_subdirectory("samples/board_sample")
add_subdirectory("samples/gui_sample")

