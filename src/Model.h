#ifndef MODEL_H
#define MODEL_H
#include "IModel.h"
#include "Board.h"
#include "ModelMessageSystem.h"
#include "AStarPuzzleSolver.h"

class Model : public IModel
{
private:
    ModelMessageSystem      m_messageSystem;
    AStarPuzzleSolver       m_solver;
    std::list<NodePtr>      m_solutionPath;
public:
    virtual bool Initialize();
    virtual bool IsEnded() const;
    virtual void NextStep();
    virtual bool AddSubscriber(IModelSubscriberPtr s);
    virtual bool RemoveSubscriber(IModelSubscriberPtr s);
private:
    Board DoPuzzleInitializing();
};

#endif