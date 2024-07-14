#ifndef __CHESS__BOARD__BOARD__HPP__
#define __CHESS__BOARD__BOARD__HPP__

#include <array>

#include <board_types.hpp>
#include <piece.hpp>
#include <space.hpp>

namespace chess::board {
    constexpr int RANKS = 8;
    constexpr int FILES = 8;

    struct column : private std::array< space, RANKS > {  // each collumn is 8 spaces
        using underlying_arr = std::array< space, RANKS >;
        // operator[] overloads
        space const & operator[]( rank_t rank ) const
        {
            return underlying_arr::operator[]( static_cast< int >( rank ) - 1 );
        }

        space & operator[]( rank_t rank )
        {
            return underlying_arr::operator[]( static_cast< int >( rank ) - 1 );  //
        }

        space const & operator[]( int ind ) const { return underlying_arr::operator[]( ind ); }

        space & operator[]( int ind )
        {
            return underlying_arr::operator[]( ind );  //
        }
    };

    class board {
    public:
        board();

        space select( rank_t rank, file_t file );  // returns the space specified
        bool  move( space & src, space & dst );  // moves the piece from src to dst, returns false is there is no piece
                                                 // on src, true otherwise

        // operator[] overloads
        column const & operator[]( file_t file ) const { return spaces[static_cast< int >( file ) - 1]; }
        column &       operator[]( file_t file ) { return spaces[static_cast< int >( file ) - 1]; }

    private:
        std::array< column, FILES >        spaces;  // the board is made of 8 columns
        static std::array< column, FILES > construct_spaces();

        // returns the piece that goes on this space when the board is initalized or std::nullopt if none
        static std::optional< piece_t > default_piece( file_t const & file, rank_t const & rank );
    };

}  // namespace chess::board

#endif