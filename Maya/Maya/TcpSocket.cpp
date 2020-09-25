#include "pch.h"
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <stdexcept>
#include <array>
#include <iostream> // TODO remove
#include "TcpSocket.hpp"


TcpClientSocket::TcpClientSocket(const std::string& ip, uint32_t port) :
    Socket(AF_INET, SOCK_STREAM)
{
    connect_to_server(ip, port);
}

void TcpClientSocket::connect_to_server(const std::string& ip, uint32_t port)
{
    sockaddr_in server_address{};

    if (inet_pton(AF_INET, ip.c_str(), &(server_address.sin_addr)) != 1)
    {
        throw std::system_error(std::error_code(errno, std::system_category()), "Failed to resolve address.");
    }
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    if (connect(s, reinterpret_cast<sockaddr *>(&server_address), sizeof(server_address)) < 0)
    {
        throw std::system_error(std::error_code(errno, std::system_category()), "Failed to connect.");
    }

    // TODO remove
    std::cout << "Connected" << std::endl;
}

Buffer TcpClientSocket::recv(size_t size)
{
    Buffer reply(size);

    size_t recv_size = ::recv(s, reinterpret_cast<char*>(reply.data()), reply.size(), 0);
    if (recv_size == SOCKET_ERROR)
    {
        throw std::system_error(std::error_code(errno, std::system_category()), "Failed to recv from socket.");
    }

    return reply;
}
