#include <display.hpp>
#include <exception>
#include <iostream>

#include <atomic>

#include <csignal>

using namespace chess::display;

std::atomic_flag should_close;

void signal_handle( int signum )
{
    should_close.test_and_set();
    should_close.notify_one();
}

int main()
{
    std::signal( SIGINT, signal_handle );
    try {
        should_close.clear();
        display disp( "MATTHEW BELANGER CHESS APP" );
        disp.launch_window();

        while ( !should_close.test() ) {  // wait until exit
            should_close.wait( false );
        }
    }
    catch ( std::exception const & e ) {
        std::cout << e.what() << "\n";
    }
}