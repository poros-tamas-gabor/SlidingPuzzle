#ifndef VIEW_H
#define VIEW_H
#include "IView.h"

class View : public IView
{
private:
    Board _currentBoard;
    void Print() const;
public:
    virtual ~View() {}
    virtual void RenderFrame() const override;
    virtual void Update(const Board& b) override;
    virtual void Initialize() override;
};

#endif