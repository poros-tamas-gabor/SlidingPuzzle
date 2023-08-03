#ifndef MODEL_H
#define MODEL_H
#include "IModel.h"
#include "Board.h"
#include "ModelMessageSystem.h"

class Model : public IModel
{
private:
    Board               m_board;
    ModelMessageSystem  m_messageSystem;
    
public:
    virtual bool Initialize();
    virtual bool IsReady() const;
    virtual void NextStep();
    virtual bool AddSubscriber(IModelSubscriberPtr s);
    virtual bool RemoveSubscriber(IModelSubscriberPtr s);
private:
    Board DoPuzzleInitializing();
};

#endif