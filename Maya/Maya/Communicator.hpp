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

    Buffer get_key_from_server();

private:
    TcpClientSocket s;
};

