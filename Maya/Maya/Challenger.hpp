#pragma once
#include "WinSockUtils.hpp"
#include "Communicator.hpp"

class Challenger
{
private:
    static constexpr char server_ip[] = "127.0.0.1";
    static constexpr uint32_t server_port = 12345;

public:
    Challenger();
    virtual ~Challenger() = default;

private:
    const WinSockUtils socket_enviroment;
    Communicator commander;
};

