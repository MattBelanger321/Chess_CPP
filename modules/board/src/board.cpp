#include "board_types.hpp"
#include <board.hpp>
#include <cassert>
#include <optional>
#include <stdexcept>

namespace chess::board {

    board::board() : spaces( construct_spaces() ) {}

    std::array< column, FILES > board::construct_spaces()
    {
        std::array< column, FILES > spaces;

        int pointer_1d = 0;  // counts the number of spaces inserted
        for ( int i = 0; i < FILES; i++ ) {
            for ( int j = 0; j < RANKS; j++ ) {
                auto file    = file_t( i + 1 );
                auto rank    = rank_t( j + 1 );
                spaces[i][j] = space( file, rank, colour_t( pointer_1d++ % 2 ), default_piece( file, rank ) );
            }
        }

        assert( pointer_1d == FILES * RANKS );  // sanity check
        return spaces;
    }

    space & board::select( file_t file, rank_t rank )
    {
        if ( static_cast< int >( file ) < 1 || static_cast< int >( file ) > FILES ) {
            throw std::runtime_error( "FILE OUT OF BOUNDS, CANNOT SELECT SPACE" );
        }

        if ( static_cast< int >( rank ) < 1 || static_cast< int >( rank ) > RANKS ) {
            throw std::runtime_error( "RANK OUT OF BOUNDS, CANNOT SELECT SPACE" );
        }

        return ( *this )[file][rank];
    }

    bool board::move( space & src, space & dst )
    {
        if ( !src.piece.has_value() ) {
            return false;  // there is no piece to move
        }

        dst.piece                  = src.piece;
        dst.piece->piece_has_moved = true;
        src.piece.reset();

        return true;
    }

    std::optional< piece_t > board::default_piece( file_t const & file, rank_t const & rank )
    {
        if ( rank == rank_t::one ) {
            switch ( file ) {
            case file_t::a:
                return piece_t( piece_type::rook, colour_t::white );
            case file_t::b:
                return piece_t( piece_type::knight, colour_t::white );
            case file_t::c:
                return piece_t( piece_type::bishop, colour_t::white );
            case file_t::d:
                return piece_t( piece_type::queen, colour_t::white );
            case file_t::e:
                return piece_t( piece_type::king, colour_t::white );
            case file_t::f:
                return piece_t( piece_type::bishop, colour_t::white );
            case file_t::g:
                return piece_t( piece_type::knight, colour_t::white );
            case file_t::h:
                return piece_t( piece_type::rook, colour_t::white );
            default:
                throw std::runtime_error( "INVALID FILE GIVEN" );  // should never happen
            }
        }
        else if ( rank == rank_t::two ) {
            switch ( file ) {
            case file_t::a:
                return piece_t( piece_type::pawn, colour_t::white );
            case file_t::b:
                return piece_t( piece_type::pawn, colour_t::white );
            case file_t::c:
                return piece_t( piece_type::pawn, colour_t::white );
            case file_t::d:
                return piece_t( piece_type::pawn, colour_t::white );
            case file_t::e:
                return piece_t( piece_type::pawn, colour_t::white );
            case file_t::f:
                return piece_t( piece_type::pawn, colour_t::white );
            case file_t::g:
                return piece_t( piece_type::pawn, colour_t::white );
            case file_t::h:
                return piece_t( piece_type::pawn, colour_t::white );
            default:
                throw std::runtime_error( "INVALID FILE GIVEN" );  // should never happen
            }
        }
        else if ( rank == rank_t::eight ) {
            switch ( file ) {
            case file_t::a:
                return piece_t( piece_type::rook, colour_t::black );
            case file_t::b:
                return piece_t( piece_type::knight, colour_t::black );
            case file_t::c:
                return piece_t( piece_type::bishop, colour_t::black );
            case file_t::d:
                return piece_t( piece_type::queen, colour_t::black );
            case file_t::e:
                return piece_t( piece_type::king, colour_t::black );
            case file_t::f:
                return piece_t( piece_type::bishop, colour_t::black );
            case file_t::g:
                return piece_t( piece_type::knight, colour_t::black );
            case file_t::h:
                return piece_t( piece_type::rook, colour_t::black );
            default:
                throw std::runtime_error( "INVALID FILE GIVEN" );  // should never happen
            }
        }
        else if ( rank == rank_t::seven ) {
            switch ( file ) {
            case file_t::a:
                return piece_t( piece_type::pawn, colour_t::black );
            case file_t::b:
                return piece_t( piece_type::pawn, colour_t::black );
            case file_t::c:
                return piece_t( piece_type::pawn, colour_t::black );
            case file_t::d:
                return piece_t( piece_type::pawn, colour_t::black );
            case file_t::e:
                return piece_t( piece_type::pawn, colour_t::black );
            case file_t::f:
                return piece_t( piece_type::pawn, colour_t::black );
            case file_t::g:
                return piece_t( piece_type::pawn, colour_t::black );
            case file_t::h:
                return piece_t( piece_type::pawn, colour_t::black );
            default:
                throw std::runtime_error( "INVALID FILE GIVEN" );  // should never happen
            }
        }

        return std::nullopt;  //
    }

}  // namespace chess::board