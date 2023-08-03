#include "App.h"
#include <iostream>
#include "Model.h"
#include "View.h"

bool App::Initialize()
{
    m_model = std::make_shared<Model>();
    if(m_model == nullptr)
        return false;

    m_view  = std::make_shared<View>();
    if(m_view == nullptr)
        return false;
    
    m_model->AddSubscriber(m_view);
    m_model->Initialize();
    m_view->Initialize();

    return true;
}
void App::Run()
{
    if(m_model == nullptr || m_view == nullptr)
        throw 2;
    
    m_view->RenderFrame();

    while (!m_model->IsReady())
    {
        m_model->NextStep();
        m_view->RenderFrame();
        break;
    }
    
}