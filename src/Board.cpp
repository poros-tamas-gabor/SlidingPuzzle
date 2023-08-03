#include "Board.h"
#include "SPException.h"
#include <iostream>

Board::Board() : m_rows({ row{1,2,3}, row{4,5,6}, row{7,8,0}}), m_ZeroCoord({2,2})
{
    CollectValidSlidingDirection();
}
Board::Board(const std::array<int, 9>& array)
{
    for(int i = 0; i < 9; i++)
    {
        int row = i / 3;
        int col = i % 3;

        m_rows.at(row).at(col) = array.at(i);
    }
}
const std::array<row, 3>& Board::GetBoard() const {return m_rows;}
const std::vector<Direction>& Board::GetValidDirection() const {return m_validDirection;}

bool Board::IsEndState() const
{
    if( !(m_ZeroCoord.first == 2 && m_ZeroCoord.second == 2))
    {
        return false;
    }
    
    int i = 1;
    for(const row& row : m_rows)
    {
        for(int n : row)
        {
            if(i != n && i < 9)
                return false;
            
            i++;
        }
    }
    return true;
}

bool Board::IsValid() const
{
    std::array<int, 9> counter;
    for(int i = 0; i < 9; i++)
    {
        counter.at(i) = 0;
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int num = m_rows.at(i).at(j);
            if (num == 0 && m_ZeroCoord != coordinate({i,j}))
                return false;

            counter.at(num) += 1;
        }
    }
    for(int i = 0; i < 9; i++)
    {
        if(counter.at(i) != 1)
            return false;
    }
    return true;
}
void Board::DoSliding(Direction d)
{
    if(!IsValidSlidingDirection(d))
    {
        THROW_SPEXCEPTION("Error: Not Valid direction");
    }

    coordinate coord = DirectionToCoordinate(d);
    
    //Copy the number to the place of zero
    m_rows.at(m_ZeroCoord.first).at(m_ZeroCoord.second) = m_rows.at(m_ZeroCoord.first + coord.first).at(m_ZeroCoord.second + coord.second);

    //Set the new zero coordinate
    m_ZeroCoord = coordinate({m_ZeroCoord.first + coord.first, m_ZeroCoord.second + coord.second});

    //Set the zero
    m_rows.at(m_ZeroCoord.first).at(m_ZeroCoord.second) = 0;

    CollectValidSlidingDirection();
}

void Board::CollectValidSlidingDirection()
{
    m_validDirection.clear();
    if(m_ZeroCoord.first != 0)
    {
        m_validDirection.push_back(UP);
    }
    if(m_ZeroCoord.first != 2)
    {
        m_validDirection.push_back(DOWN);
    }
    if(m_ZeroCoord.second != 0)
    {
        m_validDirection.push_back(LEFT);
    }
    if(m_ZeroCoord.second != 2)
    {
        m_validDirection.push_back(RIGHT);
    }
}
bool Board::IsValidSlidingDirection(Direction d)
{
    return std::find(m_validDirection.begin(), m_validDirection.end(), d) != m_validDirection.end();
}

coordinate Board::DirectionToCoordinate(Direction d)
{
    switch (d)
    {
    case LEFT:
        return coordinate(0,-1);
    case UP:
        return coordinate(-1,0);
    case RIGHT:
        return coordinate(0,1);
    case DOWN:
        return coordinate(1,0);
    default:
        return coordinate(0,0)
;    }
}
