#pragma once

#include <cstdint>
#include <string>
#include <WinSock2.h>
#include "Socket.hpp"

class TcpClientSocket : public Socket
{
public:
    TcpClientSocket(const std::string& ip, uint32_t port);
    virtual ~TcpClientSocket() = default;

private:
    void connect_to_server(const std::string&, uint32_t);
};

