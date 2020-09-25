#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "TcpSocket.hpp"

class Communicator
{
public:
    Communicator(std::string, uint32_t);
    virtual ~Communicator() = default;

    Buffer get_password();

private:
    TcpClientSocket s;
};

