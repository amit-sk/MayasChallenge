#include "pch.h"
#include <WinSock2.h>
#include <system_error>
#include "WinSockUtils.hpp"

#pragma comment(lib,"ws2_32.lib")

void WinSockUtils::initialize_winsock()
{
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        throw std::system_error(std::error_code(errno, std::system_category()));
    }
}
