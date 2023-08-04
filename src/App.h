#ifndef APP_H
#define APP_H
#include "IModel.h"
#include "IView.h"

// The created application follows a 2-layered architectural pattern: model-view.
// The model is responsible for calculations and data handling.
// The view is responsible for displaying the current state of the model.
// In this version, the view prints out the state of the model to the terminal.

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