#include "pch.h"
#include <iostream>
#include <stdexcept>
#include "WinSockUtils.hpp"

int main()
{
    try
    {
        WinSockUtils::initialize_winsock();
        std::cout << "Hello World!\n"; 
        return 0;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
        return 1; //TODO status
    }
    catch (...)
    {
        std::cerr << "Unknown Error." << std::endl;
        return 1; //TODO
    }
}

