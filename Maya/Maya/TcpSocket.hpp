#pragma once

#include <WinSock2.h>
#include "Socket.hpp"

class TcpSocket : public Socket
{
public:
    TcpSocket();
    virtual ~TcpSocket();
};

