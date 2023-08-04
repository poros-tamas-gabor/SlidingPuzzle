#ifndef I_MODEL_SUBSCRIBER_H
#define I_MODEL_SUBSCRIBER_H

#include "Node.h"
#include <memory>

///////////////////////////////////////////////////////////////////////////////
// IModelSubscriber.h
// ==================
// 
// The `IModelSubscriber` interface is a way for multiple classes to receive updates 
// from the Model component without needing to directly access its state.
// 
// The `IModelSubscriber` interface is based on Observer pattern in software design.
// It defines a set of methods that must be implemented by any class that wants to subscribe to changes in the state of the Model component.
// 
// Classes that implement the `IModelSubscriber` interface are responsible for defining how they handle updates from the Model component.
//
// AUTHOR: TAMAS GABOR POROS
// CREATED: 2023-08-04
///////////////////////////////////////////////////////////////////////////////

class IModelSubscriber
{
public:
    virtual ~IModelSubscriber() {}
    virtual void Update(NodePtr node) = 0;  
};

typedef std::shared_ptr<IModelSubscriber> IModelSubscriberPtr;

#endif