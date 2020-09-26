#include "pch.h"
#include "File.hpp"
#include "AES.hpp"
#include "Challenger.hpp"

#include <libloaderapi.h>


Challenger::Challenger() :
    socket_enviroment(),
    communicator(SERVER_IP, SERVER_PORT),
    iv_manager(),
    decryptor()
{}

void Challenger::run_challenge()
{
    Buffer key_digits = communicator.get_key_from_server();
    iv_manager.modify_iv(key_digits);
    InitialVectorType iv = iv_manager.get_initial_vector();

    auto b = decryptor.decrypt_message(iv, key_digits);
}
