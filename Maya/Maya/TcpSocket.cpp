#include "pch.h"
#include <WinSock2.h>
#include "TcpSocket.hpp"


TcpSocket::TcpSocket() :
    Socket(AF_INET, SOCK_STREAM)
{}

TcpSocket::~TcpSocket()
{
}

