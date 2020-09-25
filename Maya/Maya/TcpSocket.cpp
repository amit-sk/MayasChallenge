#include "pch.h"
#include <WinSock2.h>
#include <system_error>
#include <iostream>
#include "TcpSocket.hpp"


TcpSocket::TcpSocket() :
    s(create_socket())
{}


TcpSocket::~TcpSocket()
{
    // Best effort
    closesocket(s);
}

SOCKET TcpSocket::create_socket()
{
    SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == INVALID_SOCKET)
    {
        throw std::system_error(std::error_code(errno, std::system_category()), "Failed to create socket.");
    }
    return s;
}
