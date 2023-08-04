#ifndef NODE_H
#define NODE_H

#include "Board.h"
#include<iostream>
class Node;

typedef std::shared_ptr<Node> NodePtr;

class Node
{
private:
    Board       m_board;
    unsigned    m_pathCost;
    NodePtr     m_parentNode;
    Direction   m_prevDirection;
public:
    Node(Board board, unsigned pathcost, NodePtr parent, Direction direction) : m_board(board), m_pathCost(pathcost), m_parentNode(parent), m_prevDirection(direction) {}

    void            SetPathCost(unsigned pathcost) {m_pathCost = pathcost;}
    unsigned        GetPathCost() const {return m_pathCost;}
    unsigned        GetTotalCost() const {return m_pathCost + m_board.GetManhattanHeuristicValue();}   
    const Board&    GetBoard() const {return m_board;}
    void            SetParentNode(NodePtr parent) {m_parentNode = parent;}
    NodePtr         GetParentNode() const {return m_parentNode;}
    void            SetPrevDirection(Direction direction) {m_prevDirection = direction;}
    Direction       GetPrevDirection() const {return m_prevDirection;}
    void            Print() const
    {
        std::cout << "path cost: " << m_pathCost << "; parent Node address: " << m_parentNode << ": previous Direction: " << GetDirectionName(m_prevDirection) << std::endl;
        m_board.Print();
    }
};

#endif