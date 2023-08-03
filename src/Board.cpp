#include "Board.h"
#include <iostream>
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