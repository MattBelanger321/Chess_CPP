#ifndef __CHESS__BOARD__PIECE__HPP__
#define __CHESS__BOARD__PIECE__HPP__

#include <board_types.hpp>

namespace chess::board {
    class piece_t {
    public:
        piece_t( piece_type type, colour_t colour );

    private:
        piece_type type;
        colour_t   colour;

        friend class board;  // board can modify piece
    };
}  // namespace chess::board

#endif