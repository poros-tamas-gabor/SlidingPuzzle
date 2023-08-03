#include "View.h"
#include <iostream>

void View::RenderFrame() const
{
    Print();
}

void View::Print() const
{
    const std::array<row,3>& rows = _currentBoard.GetBoard();

    std::cout << "------------" << std::endl;

    for(row r : rows)
    {
        std::cout << "| ";
        for(int i : r)
        {
            if(i != 0)
            {
                std::cout << i << " |";
            }
            else
            {
                std::cout << "  |";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "------------" << std::endl;

}
void View::Update(const Board& b)
{
    _currentBoard = b;
}
void View::Initialize(){}
