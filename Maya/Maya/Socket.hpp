#pragma once

#include <WinSock2.h>

class Socket
{
public:
    Socket(int address_family, int socket_type);
    virtual ~Socket();

private:
    static SOCKET create_socket(int address_family, int socket_type);

protected:
    SOCKET s;
};

