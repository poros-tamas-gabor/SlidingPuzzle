#ifndef VIEW_H
#define VIEW_H
#include "IView.h"


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