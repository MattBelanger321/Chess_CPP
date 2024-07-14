#ifndef __CHESS__BOARD__TYPES__HPP__
#define __CHESS__BOARD__TYPES__HPP__

#include <stdexcept>
#include <string>

namespace chess::board {
    enum class rank_t { one = 1, two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8 };
    enum class file_t { a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8 };

    enum class piece_type { king, queen, rook, knight, bishop, pawn };

    enum class colour_t { white = 1, black = 0 };

    // Convert file_t to its string representation
    inline std::string file_to_string( file_t file )
    {
        switch ( file ) {
        case file_t::a:
            return "a";
        case file_t::b:
            return "b";
        case file_t::c:
            return "c";
        case file_t::d:
            return "d";
        case file_t::e:
            return "e";
        case file_t::f:
            return "f";
        case file_t::g:
            return "g";
        case file_t::h:
            return "h";
        default:
            throw std::runtime_error( "CANNOT CONVERT GIVEN FILE TO STRING" );
        }
    }

    // Convert rank_t to its string representation
    inline std::string rank_to_string( rank_t rank )
    {
        auto rank_val = static_cast< int >( rank );
        if ( rank_val >= 1 && rank_val <= 8 ) {
            return std::to_string( rank_val );  //
        }
        else {
            throw std::runtime_error( "CANNOT CONVERT GIVEN RANK TO STRING" );
        }
    }

    inline std::string piece_to_string( piece_type piece )
    {
        switch ( piece ) {
        case piece_type::king:
            return "K";
        case piece_type::queen:
            return "Q";
        case piece_type::rook:
            return "R";
        case piece_type::knight:
            return "N";
        case piece_type::bishop:
            return "B";
        case piece_type::pawn:
            return "P";
        default:
            throw std::runtime_error( "CANNOT CONVERT GIVEN PIECE TO STRING" );
        }
    }
}  // namespace chess::board

#endif