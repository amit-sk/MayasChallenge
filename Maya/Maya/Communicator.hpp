#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include "TcpSocket.hpp"

class Communicator
{
public:
    Communicator(std::string, uint32_t);
    Communicator() = default;
    virtual ~Communicator();

    std::vector<uint8_t> get_password();

private:
    TcpSocket s;
};

