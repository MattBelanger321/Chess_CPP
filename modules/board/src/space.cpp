#include <space.hpp>

namespace chess::board {

    space::space( file_t file, rank_t rank, colour_t colour, std::optional< piece_t > piece ) :
        rank( rank ), file( file ), colour( colour ), piece( piece )
    {
    }

}  // namespace chess::board