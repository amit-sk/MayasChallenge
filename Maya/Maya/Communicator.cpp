#include "pch.h"
#include "Communicator.hpp"


Communicator::Communicator(std::string ip, uint32_t port) :
    s(ip, port)
{}


Buffer Communicator::get_password()
{
    Buffer pass = s.recv(1024);
    return pass;
}