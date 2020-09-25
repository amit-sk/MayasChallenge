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
    Buffer inputted_nibbles;

    for (const auto& byte : inputted_key)
    {
        const auto first_digit = byte / 10;
        const auto second_digit = byte % 10;

        if (first_digit > 9 or first_digit < 6)
        {
            throw ProjectException(ProjectStatus::NonAsciiCharacterInputted);
        }

        inputted_nibbles.emplace_back(first_digit);
        inputted_nibbles.emplace_back(second_digit);
    }

    return inputted_nibbles;
}