#ifndef __CHESS__BOARD__TYPES__HPP__
#define __CHESS__BOARD__TYPES__HPP__

namespace chess::board {
    enum class rank_t { one = 1, two = 2, three = 3, four = 4, five = 5, six = 6, seven = 7, eight = 8 };
    enum class file_t { a = 1, b = 2, c = 3, d = 4, e = 5, f = 6, g = 7, h = 8 };

    enum class piece_type { king, queen, rook, knight, bishop, pawn };

    enum class colour_t { white = 1, black = 0 };
}  // namespace chess::board

#endif