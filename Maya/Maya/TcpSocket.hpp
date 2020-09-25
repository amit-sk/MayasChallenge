#pragma once

#include <cstdint>
#include <string>
#include <vector>
#include <WinSock2.h>
#include "Socket.hpp"

using Buffer = std::vector<uint8_t>;

class TcpClientSocket : public Socket
{
public:
    TcpClientSocket(const std::string& ip, uint32_t port);
    virtual ~TcpClientSocket() = default;

    Buffer recv(size_t size);

private:
    void connect_to_server(const std::string&, uint32_t);
};

