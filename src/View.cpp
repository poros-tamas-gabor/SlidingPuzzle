#include "View.h"
#include <iostream>

void View::RenderFrame() const
{
    Print();
}
void View::Print() const
{
    if(m_currentNode)
    {
        if(m_currentNode->GetParentNode() != nullptr)
        {
            std::cout << "      |      " << std::endl;
            std::cout << "      V      " << std::endl;
        }
        else
        {
            std::cout << "--------------------------------" << std::endl;
            std::cout << "8 pieces sliding puzzle solution" << std::endl;
            std::cout << "--------------------------------" << std::endl << std::endl;
        }
        m_currentNode->Print();
    }
}
void View::Update(NodePtr b)
{
    m_currentNode = b;
}
bool View::Initialize(){return true;}
