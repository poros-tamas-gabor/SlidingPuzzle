#ifndef MODEL_MESSAGE_SYSYEM_H
#define MODEL_MESSAGE_SYSYEM_H

#include "IModelSubscriber.h"
#include <vector>

/////////////////////////////////////////////////////////////////////////////
// ModelMessageSystem.h
// ====================
// 
// The communication between the model and the observers is implemented using the Observer design pattern.
// The IModelSubscriber interface specifies the Update function, capable of receiving a Node type element.
//
// The Observer design pattern is provided by the ModelMessageSystem class.
// Observers of type IModelSubscriber can subscribe to this object.
// When the state of the IModel object changes, the ModelMessageSystem object notifies the subscribers through the Publish method.
//
// AUTHOR: TAMAS GABOR POROS
// CREATED: 2023-08-04
///////////////////////////////////////////////////////////////////////////////

class ModelMessageSystem
{
private:
    std::vector<IModelSubscriberPtr> m_subscribers;
public:
    void Publish(NodePtr node) const;
	bool Subscribe(IModelSubscriberPtr view);
	bool Unsubscribe(IModelSubscriberPtr view);    
};


#endif