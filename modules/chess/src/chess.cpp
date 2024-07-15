#include "board.hpp"
#include <chess.hpp>

namespace chess::game {

    chess::chess() : state( game_state::idle ) {}

    void chess::start_game()
    {
        state      = game_state::white_move;
        game_board = board::board();  // create new board
    }

    void chess::end_game() { state = game_state::idle; }

    chess::~chess() { end_game(); }

}  // namespace chess::game