cmake_minimum_required(VERSION 3.5)

project(glfw_bindings LANGUAGES CXX)

find_package(imgui REQUIRED CONFIG)
find_package(glfw3 REQUIRED CONFIG)
find_package(glew CONFIG REQUIRED)

add_library(${PROJECT_NAME}
	"include/imgui_impl_glfw.h"
	"include/imgui_impl_opengl3.h"
	"include/imgui_impl_opengl3_loader.h"

	"src/imgui_impl_glfw.cpp"
	"src/imgui_impl_opengl3.cpp"
)


target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

target_include_directories(${PROJECT_NAME}
    PUBLIC
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>

    PRIVATE
)

target_compile_definitions(${PROJECT_NAME} PUBLIC IMGUI_IMPL_OPENGL_LOADER_GLEW)
target_link_libraries(${PROJECT_NAME}
    PUBLIC
	imgui::imgui
    glfw::glfw
	GLEW::glew_s
	
)