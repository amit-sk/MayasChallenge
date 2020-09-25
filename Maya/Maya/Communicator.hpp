#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "TcpSocket.hpp"

class Communicator
{
public:
    Communicator(std::string, uint32_t);
    virtual ~Communicator();

    std::vector<uint8_t> get_password();

private:
    TcpClientSocket s;
};

