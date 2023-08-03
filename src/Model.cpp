#include "Model.h"

bool Model::Initialize()
{
    m_board = Board({3,2,1,6,4,5,9,8,7});
    m_messageSystem.Publish(m_board);
}

bool Model::IsReady() const
{
    return m_board.IsEndState();
}

void Model::NextStep() {}


bool Model::AddSubscriber(IModelSubscriberPtr s)
{
    return m_messageSystem.Subscribe(s);
}
bool Model::RemoveSubscriber(IModelSubscriberPtr s)
{
    return m_messageSystem.Unsubscribe(s);
}
