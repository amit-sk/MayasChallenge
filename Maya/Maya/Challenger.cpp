#include "pch.h"
#include "Challenger.hpp"


Challenger::Challenger() :
    socket_enviroment(),
    communicator(server_ip, server_port),
    iv_manager()
{}

void Challenger::run_challenge()
{
    Buffer key_digits = communicator.get_key_from_server();
    iv_manager.modify_iv(key_digits);
}
