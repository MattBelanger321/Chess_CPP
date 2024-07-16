cmake_minimum_required(VERSION 3.5)

add_subdirectory("bindings")

project(imgui_initializer LANGUAGES CXX)

add_library(${PROJECT_NAME}
    "include/imgui_initializer.hpp"

    "src/imgui_initializer.cpp"
)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

    PRIVATE
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
    glfw_bindings
)