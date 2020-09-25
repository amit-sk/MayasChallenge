#include "pch.h"
#include <system_error>
#include "Socket.hpp"


Socket::Socket(int address_family, int socket_type) :
    s(create_socket(address_family, socket_type))
{}


Socket::~Socket()
{
    // Best effort
    closesocket(s);
}

SOCKET Socket::create_socket(int address_family, int socket_type)
{
    SOCKET s = socket(address_family, socket_type, 0);
    if (s == INVALID_SOCKET)
    {
        throw std::system_error(std::error_code(errno, std::system_category()), "Failed to create socket.");
    }

    return s;
}
