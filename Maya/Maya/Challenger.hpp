#pragma once

#include "Buffer.hpp"
#include "WinSockUtils.hpp"
#include "Communicator.hpp"
#include "InitialVectorManager.hpp"
#include "Decryptor.hpp"

class Challenger
{
private:
    static constexpr char SERVER_IP[] = "80.73.78.75";
    static constexpr uint32_t SERVER_PORT = 26999;

public:
    Challenger();
    virtual ~Challenger() = default;

    void run_challenge();

private:
    void execute_digits(const Buffer&);

private:
    const WinSockUtils socket_enviroment;
    Communicator communicator;
    InitialVectorManager iv_manager;
    MessageDecryptor message_decryptor;
};

