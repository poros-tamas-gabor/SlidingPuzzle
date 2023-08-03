#ifndef APP_H
#define APP_H
#include "IModel.h"
#include "IView.h"

class App
{
private:
    IModelPtr   m_model;
    IViewPtr    m_view;
public:
    bool Initialize();
    void Run();
};
#endif