#include "pch.h"
#include <string>
#include "ProjectException.hpp"
#include "Communicator.hpp"


Communicator::Communicator(std::string ip, uint32_t port) :
    s(ip, port)
{}


Buffer Communicator::get_key_from_server()
{
    Buffer inputted_key = s.recv(1024);
    Buffer inputted_nibbles(inputted_key.size() * 2);

    for (const auto& byte : inputted_key)
    {
        const auto& string_byte = std::to_string(byte);

        if (string_byte.length() != 2 or (byte / 10) < 6)
        {
            throw ProjectException(ProjectStatus::NonAsciiCharacterInputted);
        }

        inputted_nibbles.emplace_back(string_byte[0]);
        inputted_nibbles.emplace_back(string_byte[1]);
    }

    return inputted_nibbles;
}