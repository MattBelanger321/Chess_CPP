#ifndef __CHESS__DISPLAY__DISPLAY__HPP__
#define __CHESS__DISPLAY__DISPLAY__HPP__

#include <imgui_initializer.hpp>

#include <string>
#include <thread>

namespace chess::display {
    class display : private imgui_initalizer {
    public:
        display( std::string window_name );
        ~display();

        void launch_window();

    private:
        std::thread render_thread;
        void        render();
    };
}  // namespace chess::display

#endif