#ifndef IVIEW_H
#define IVIEW_H

#include "IModelSubscriber.h"

class IView : public IModelSubscriber
{
public:
    virtual ~IView() {}
    virtual void RenderFrame() const = 0;
    virtual void Initialize() = 0; 
};
typedef std::shared_ptr<IView> IViewPtr;
#endif