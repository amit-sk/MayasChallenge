#include "pch.h"
#include "Communicator.hpp"


Communicator::Communicator(std::string ip, uint32_t port) :
    s(ip, port)
{}


Communicator::~Communicator()
{
}
