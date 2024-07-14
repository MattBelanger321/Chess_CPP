#ifndef __CHESS__BOARD__PIECE__HPP__
#define __CHESS__BOARD__PIECE__HPP__

#include <board_types.hpp>

#include <ostream>
namespace chess::board {
    class piece_t {
    public:
        piece_t( piece_type type, colour_t colour );
        bool has_moved();

        friend std::ostream & operator<<( std::ostream & os, const piece_t & s );

    private:
        piece_type type;
        colour_t   colour;
        bool       piece_has_moved;  // set if this piece was placed on a board and was moved from its original position

        friend class board;  // board can modify piece
    };

    inline std::ostream & operator<<( std::ostream & os, const piece_t & p )
    {
        os << ( p.colour == colour_t::white ? "w" : "b" ) << piece_to_string( p.type );

        return os;
    }
}  // namespace chess::board

#endif