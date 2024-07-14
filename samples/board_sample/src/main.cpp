#include "board_types.hpp"
#include <iostream>

#include <board.hpp>

using namespace chess::board;
int main()
{
    board my_board;
    std::cout << my_board << "\n";

    auto & e2 = my_board[file_t::e][rank_t::two];
    auto & e4 = my_board[file_t::e][rank_t::four];

    my_board.move( e2, e4 );

    std::cout << "\n\n";
    std::cout << my_board;
}