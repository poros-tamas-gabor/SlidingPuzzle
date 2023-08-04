#ifndef VIEW_H
#define VIEW_H
#include "IView.h"

/////////////////////////////////////////////////////////////////////////////
// View.h
// ====================
// 
// The View class represents the view component of the application.
// It is responsible for displaying the current state of the model component by printing it to the terminal.
// The view component receives the current model state through an observer pattern between the model and the view.
//
// AUTHOR: TAMAS GABOR POROS
// CREATED: 2023-08-04
///////////////////////////////////////////////////////////////////////////////



class View : public IView
{
private:
    NodePtr     m_currentNode;
    void        Print() const;
public:
    virtual      ~View() {}
    virtual void RenderFrame() const override;
    virtual void Update(NodePtr node) override;
    virtual bool Initialize() override;
};

#endif