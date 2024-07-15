#ifndef __CHESS__GAME__CHESS__HPP__
#define __CHESS__GAME__CHESS__HPP__

#include <board.hpp>

namespace chess::game {

    enum class game_state {
        idle,                  // no game is active
        white_move,            // white's move, no check
        black_move,            // black's move no check
        white_check,           // white's in check
        black_check,           // black's in check
        white_checkmate,       // white lost by checkmate
        black_checkmate,       // black lost by checkmate
        white_resign,          // white resigned
        black_resign,          // black resign
        white_stalemate,       // stalemate, white cannot move
        black_stalemate,       // stalemate, black cannot move
        insufficent_material,  // stalemate, insufficent material
        fifty_move,            // stalemate by 50 move rule
        white_draw,            // white is offering a draw
        black_draw,            // black is offering a draw
        draw_accepted          // draw accepted
    };

    class chess {
    public:
        chess();
        ~chess();

        void start_game();
        void end_game();

    private:
        game_state   state;
        board::board game_board;
    };

}  // namespace chess::game

#endif