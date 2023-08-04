#ifndef MODEL_H
#define MODEL_H
#include "IModel.h"
#include "Board.h"
#include "ModelMessageSystem.h"
#include "AStarPuzzleSolver.h"

///////////////////////////////////////////////////////////////////////////////
// Model.h
// ====================
// 
// The Model class represents the model component of the application.
// It is responsible for creating the initial state of the puzzle (by generating a solvable starter position),
// finding the solution path using the AStarPuzzleSolver class, and creating an iterable solution path after the Initialize function is called.
// The client (App) uses the IsEnded and NextStep functions to iterate over the solution path.
//
// The evaluation function of the A* algorithm uses the path cost of the Node and the Manhattan Heuristic Value.
//
// AUTHOR: TAMAS GABOR POROS
// CREATED: 2023-08-04
///////////////////////////////////////////////////////////////////////////////


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