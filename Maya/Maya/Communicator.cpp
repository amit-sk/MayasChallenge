#include "pch.h"
#include "Communicator.hpp"


Communicator::Communicator(std::string ip, uint32_t port) :
    s(ip, port)
{}


Buffer Communicator::get_key_from_server()
{
    Buffer inputted_key = s.recv(1024);

    for (const auto& byte : inputted_key)
    {
        uint8_t first_nibble = (byte & 0xF0) >> 4;
        uint8_t second_nibble = byte & 0xF;

        if (first_nibble > 9 or first_nibble < 6) // TODO consider obfuscating this check a bit
        {
            
        }
    }
    return inputted_key;
}