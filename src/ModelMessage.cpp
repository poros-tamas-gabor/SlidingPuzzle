#include "ModelMessageSystem.h"

void ModelMessageSystem::Publish(NodePtr node) const
{
    for(IModelSubscriberPtr subscriber : m_subscribers)
    {
        subscriber->Update(node);
    }
}
bool ModelMessageSystem::Subscribe(IModelSubscriberPtr subscriber)
{
	if (std::find(this->m_subscribers.begin(), this->m_subscribers.end(), subscriber) != this->m_subscribers.end())
	{
		return false;
	}
	else {
		this->m_subscribers.push_back(subscriber);
		return true;
	}
}
bool ModelMessageSystem::Unsubscribe(IModelSubscriberPtr subscriber)
{
	if (std::find(this->m_subscribers.begin(), this->m_subscribers.end(), subscriber) != this->m_subscribers.end())
	{
		m_subscribers.erase(std::remove(this->m_subscribers.begin(), this->m_subscribers.end(), subscriber));
		return true;
	}
	return false;
}