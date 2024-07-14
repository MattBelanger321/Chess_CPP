#include <piece.hpp>

namespace chess::board {

    piece_t::piece_t( piece_type type, colour_t colour ) : type( type ), colour( colour ), piece_has_moved( false ) {}
    bool piece_t::has_moved() { return piece_has_moved; }

}  // namespace chess::board