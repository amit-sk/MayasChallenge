#pragma once

#include "Buffer.hpp"
#include "WinSockUtils.hpp"
#include "Communicator.hpp"
#include "InitialVectorManager.hpp"
#include "Decryptor.hpp"
#include "DirectioningStringsDecryptor.hpp"

class Challenger
{
private:
    static constexpr char SERVER_IP[] = "127.0.0.1"; // TODO change address
    static constexpr uint32_t SERVER_PORT = 12345;

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
    DirectioningStringsDecryptor directioning_strings_decryptor;
};

