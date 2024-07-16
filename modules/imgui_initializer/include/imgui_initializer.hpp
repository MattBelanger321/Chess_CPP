#ifndef __CHESS__IMGUI_INIT__INITALIZER__HPP__
#define __CHESS__IMGUI_INIT__INITALIZER__HPP__

#include <imgui.h>

#include <functional>
#include <string>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace chess::display {

    class imgui_initalizer {
    public:
        imgui_initalizer( std::string window_name );
        ~imgui_initalizer();

        bool init();
        void run( std::function< void() > & render_function );
        void stop();

        static void error_callback( int error, const char * description );

        GLFWwindow * window;
        const char * glsl_version;

    private:
        std::string window_name;

        void main_loop( std::function< void() > & render_function );
    };

}  // namespace chess::display

#endif