#ifndef BOARD_H
#define BOARD_H

#include <array>

typedef std::array<int, 3> row;
typedef std::pair<int, int> coordinate;

class Board
{
private:
    std::array<row, 3>              m_rows;
    coordinate                      m_ZeroCoord;

public:
    Board() : m_rows({ row{1,2,3}, row{4,5,6}, row{7,8,0}}), m_ZeroCoord({2,2}){}
    Board(const std::array<int, 9>& array);


    bool IsEndState() const;
    const std::array<row, 3>& GetBoard() const;
};

#endif