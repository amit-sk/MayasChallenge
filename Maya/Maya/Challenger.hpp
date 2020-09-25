#pragma once

#include "Buffer.hpp"
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

    void run_challenge();

private:
    const WinSockUtils socket_enviroment;
    Communicator communicator;
};

