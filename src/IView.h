#ifndef IVIEW_H
#define IVIEW_H

#include "IModelSubscriber.h"

///////////////////////////////////////////////////////////////////////////////
// IView.h
// =======
// An interface for the View component in the Model-View  architecture.
//
// The purpose of the View in MV is to display the Model's data to the user.
//
// This is only an interface and does not handle any messages. Programmers must implement a derived class to handle
// specific messages.
//
// AUTHOR: TAMAS GABOR POROS
// CREATED: 2023-08-04
///////////////////////////////////////////////////////////////////////////////

class IView : public IModelSubscriber
{
public:
    virtual ~IView() {}
    virtual void RenderFrame() const = 0;
    virtual bool Initialize() = 0; 
};
typedef std::shared_ptr<IView> IViewPtr;
#endif