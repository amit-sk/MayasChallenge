#include "pch.h"
#include <iostream>
#include <stdexcept>
#include "ProjectException.hpp"
#include "Challenger.hpp"

int main()
{
    try
    {
        Challenger challenger;
        challenger.run_challenge();
        return static_cast<int>(ProjectStatus::Success);
    }
    catch (const ProjectException& e)
    {
        std::cerr << "Caught ProjectException: status " << e.get_string_status() << std::endl;
        return static_cast<int>(e.status);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Caught Exception: " << e.what() << std::endl;
        return static_cast<int>(ProjectStatus::StandardExceptionThrown);
    }
    catch (...)
    {
        std::cerr << "Unknown Error." << std::endl;
        return static_cast<int>(ProjectStatus::UnknownExceptionThrown);
    }
}

