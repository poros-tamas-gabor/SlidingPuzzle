#ifndef MODEL_MESSAGE_SYSYEM_H
#define MODEL_MESSAGE_SYSYEM_H

#include "IModelSubscriber.h"
#include <vector>
class ModelMessageSystem
{
private:
    std::vector<IModelSubscriberPtr> m_subscribers;
public:
    void Publish(const Board& board) const;
	bool Subscribe(IModelSubscriberPtr view);
	bool Unsubscribe(IModelSubscriberPtr view);    
};


#endif