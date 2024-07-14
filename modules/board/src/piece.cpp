#include <piece.hpp>

namespace chess::board {

    piece_t::piece_t( piece_type type, colour_t colour ) : type( type ), colour( colour ) {}

}  // namespace chess::board