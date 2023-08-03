#ifndef BOARD_H
#define BOARD_H

#include <array>
#include <vector>

typedef std::array<int, 3> row;
typedef std::pair<int, int> coordinate;
enum    Direction{LEFT, UP, RIGHT, DOWN};

class Board
{
private:
    std::array<row, 3>      m_rows;
    coordinate              m_ZeroCoord;
    std::vector<Direction>  m_validDirection;

public:
    Board();
    Board(const std::array<int, 9>& array);

    bool IsEndState() const;
    bool IsValid() const;
    int  GetManhattanHeuristicValue() const;
    void DoSliding(Direction d);

    const std::array<row, 3>& GetBoard() const;
    const std::vector<Direction>& GetValidDirection() const;

private:
    void CollectValidSlidingDirection();
    bool IsValidSlidingDirection(Direction d);
    static coordinate DirectionToCoordinate(Direction d);

};


#endif