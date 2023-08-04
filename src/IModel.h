#ifndef IMODEL_H
#define IMODEL_H

#include <memory>
#include "IModelSubscriber.h"

class IModel
{
public:
    virtual ~IModel() {}
    virtual bool Initialize() = 0;
    virtual bool IsEnded() const = 0;
    virtual void NextStep() = 0;
    virtual bool AddSubscriber(IModelSubscriberPtr s) = 0;
    virtual bool RemoveSubscriber(IModelSubscriberPtr s) = 0;
};

typedef std::shared_ptr<IModel> IModelPtr;
#endif