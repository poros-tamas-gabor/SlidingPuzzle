#ifndef I_MODEL_SUBSCRIBER_H
#define I_MODEL_SUBSCRIBER_H

#include "Board.h"
#include <memory>

class IModelSubscriber
{
public:
    virtual ~IModelSubscriber() {}
    virtual void Update(const Board& b) = 0;  
};

typedef std::shared_ptr<IModelSubscriber> IModelSubscriberPtr;

#endif