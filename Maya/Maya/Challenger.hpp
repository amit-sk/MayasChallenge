#pragma once
#include "WinSockUtils.hpp"
#include "Communicator.hpp"

class Challenger
{
public:
    Challenger();
    virtual ~Challenger() = default;

private:
    const WinSockUtils socket_enviroment;
    Communicator commander;
};

