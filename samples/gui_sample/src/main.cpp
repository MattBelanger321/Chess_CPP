#include <exception>
#include <imgui_initalizer.hpp>
#include <iostream>

using namespace chess::display;
int main()
{
    try {
        imgui_initalizer        init( "MATTHEW BELANGER CHESS APP" );
        std::function< void() > render_function = []() {};
        init.run( render_function );
    }
    catch ( std::exception const & e ) {
        std::cout << e.what() << "\n";
    }
}