#ifndef __CHESS__BOARD__SPACE__HPP__
#define __CHESS__BOARD__SPACE__HPP__

#include <optional>
#include <ostream>
#include <string>

#include <board_types.hpp>
#include <piece.hpp>

namespace chess::board {
    class space {
    public:
        space( file_t file, rank_t rank, colour_t colour, std::optional< piece_t > piece );
        space() {}

        std::string coordinate() const;

        friend std::ostream & operator<<( std::ostream & os, const space & s );

    private:
        rank_t                   rank;
        file_t                   file;
        colour_t                 colour;
        std::optional< piece_t > piece;

        friend class board;  // board can modify spaces
    };

    inline std::ostream & operator<<( std::ostream & os, const space & s )
    {
        os << s.coordinate() << ":";
        if ( !s.piece ) {
            os << "xx";
        }
        else {
            os << *s.piece;
        }
        return os;
    }
}  // namespace chess::board

#endif