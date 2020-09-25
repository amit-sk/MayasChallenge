#pragma once

#include <WinSock2.h>

class TcpSocket
{
public:
    explicit TcpSocket();
    virtual ~TcpSocket();

private:
    static SOCKET create_socket();

private:
    SOCKET s;
};

