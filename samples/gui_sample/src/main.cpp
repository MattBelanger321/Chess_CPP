#include <display.hpp>
#include <exception>
#include <iostream>

using namespace chess::display;
int main()
{
    try {
        display disp( "MATTHEW BELANGER CHESS APP" );
        disp.launch_window();
    }
    catch ( std::exception const & e ) {
        std::cout << e.what() << "\n";
    }
}