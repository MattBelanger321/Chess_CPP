#ifndef __CHESS__BOARD__SPACE__HPP__
#define __CHESS__BOARD__SPACE__HPP__

#include <optional>
#include <string>

#include <board_types.hpp>
#include <piece.hpp>

namespace chess::board {
    class space {
    public:
        space( file_t file, rank_t rank, colour_t colour, std::optional< piece_t > piece );
        space() {}

        std::string coordinate();

    private:
        rank_t                   rank;
        file_t                   file;
        colour_t                 colour;
        std::optional< piece_t > piece;

        friend class board;  // board can modify spaces
    };
}  // namespace chess::board

#endif