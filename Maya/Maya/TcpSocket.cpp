#include "pch.h"
#include <WinSock2.h>
#include <ws2tcpip.h>
#include <iostream>
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

    if (connect(s, (sockaddr *)(&server_address), sizeof(server_address)) < 0)
    {
        throw std::system_error(std::error_code(errno, std::system_category()), "Failed to connect.");
    }

    std::cout << "Connected" << std::endl;
}
