#pragma once

#include <cstdint>
#include <string>
#include <vector>

class Communicator
{
public:
    Communicator(std::string, uint32_t);
    virtual ~Communicator();

    std::vector<uint8_t> get_password();

private:
    const std::string address;
    const uint32_t port;
};

