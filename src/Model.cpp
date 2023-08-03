#include "Model.h"

bool Model::Initialize()
{
    m_board = Board();
    m_messageSystem.Publish(m_board);
}

bool Model::IsReady() const
{
    return m_board.IsEndState();
}

void Model::NextStep() 
{

    m_messageSystem.Publish(m_board);
}


bool Model::AddSubscriber(IModelSubscriberPtr s)
{
    return m_messageSystem.Subscribe(s);
}
bool Model::RemoveSubscriber(IModelSubscriberPtr s)
{
    return m_messageSystem.Unsubscribe(s);
}
