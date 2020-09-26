#include "pch.h"
#include "File.hpp"
#include "AES.hpp"
#include "Challenger.hpp"

#include <fstream>


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

    Buffer decrypted_message = decryptor.decrypt_message(iv, key_digits);

    std::ofstream f("Message1.txt", std::ios::binary);
    f.write(reinterpret_cast<char*>(decrypted_message.data()), decrypted_message.size());
}
