#include "App.h"
#include <exception>
#include <iostream>

int main()
{
    App a;
    try
    {
        if(a.Initialize())
        {
            a.Run();    
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(...)
    {
        std::cerr << "Unknown Exception: No details available" << std::endl;
    }
    

    return 0;
}