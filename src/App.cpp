#include "App.h"
#include <iostream>
#include "Model.h"
#include "View.h"
#include <cstdlib>
#include "SPException.h"

// The function constructs and initializes the model and view components.
// It sets up the observer pattern between the model and the view.
bool App::Initialize()
{
    bool success;
    srand((unsigned) time(NULL));

    m_model = std::make_shared<Model>();
    if(m_model == nullptr)
        return false;

    m_view  = std::make_shared<View>();
    if(m_view == nullptr)
        return false;
    
    m_model->AddSubscriber(m_view);
    
    success = m_model->Initialize();
    if(!success)
        return false;

    success = m_view->Initialize();
    if(!success)
        return false;

    return true;
}

// The function runs until the model reaches the end state.
// In each step of the loop, it displays the current state.
void App::Run()
{
    if(m_model == nullptr || m_view == nullptr)
        THROW_SPEXCEPTION("Error: Nullpointer exception");
    
    while (!m_model->IsEnded())
    {
        m_model->NextStep();
        m_view->RenderFrame();
    } 
}