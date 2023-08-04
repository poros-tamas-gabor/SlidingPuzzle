#ifndef IMODEL_H
#define IMODEL_H

#include <memory>
#include "IModelSubscriber.h"

///////////////////////////////////////////////////////////////////////////////
// IModel.h
// ========
// An interface for the Model component in the Model-View architecture.
//
// The purpose of the Model in MV is to manage the data and logic of the application.
//
// This is only an interface and does not contain any implementation details. Programmers must implement a derived class to handle
// specific data and logic for their application.
//
// AUTHOR: TAMAS GABOR POROS
// CREATED: 2023-08-04
///////////////////////////////////////////////////////////////////////////////
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