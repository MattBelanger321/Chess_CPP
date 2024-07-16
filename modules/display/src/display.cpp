#include <display.hpp>

namespace chess::display {
    display::display( std::string window_name ) : imgui_initalizer( window_name ) {}

    void display::launch_window()
    {
        std::function< void() > render_function = [&]() { render(); };
        // clang-format off
        render_thread = std::thread(  
            [&]() {                   
                run( render_function );
            }  
        );
        // clang-format on
    }

    void display::render() {}

    display::~display()
    {
        stop();
        if ( render_thread.joinable() )
            render_thread.join();
    }
}  // namespace chess::display