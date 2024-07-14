#include "board_types.hpp"
#include <space.hpp>

namespace chess::board {

    space::space( file_t file, rank_t rank, colour_t colour, std::optional< piece_t > piece ) :
        rank( rank ), file( file ), colour( colour ), piece( piece )
    {
    }

    std::optional< piece_t > const & space::get_piece() const { return piece; }

    std::string space::coordinate() const { return file_to_string( file ) + rank_to_string( rank ); }

}  // namespace chess::board