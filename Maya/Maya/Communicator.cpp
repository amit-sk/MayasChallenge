#include "pch.h"
#include "Communicator.hpp"


Communicator::Communicator(std::string _address, uint32_t _port) :
    address(_address),
    port(_port)
{}


Communicator::~Communicator()
{
}
