#include "pch.h"
#include "File.hpp"
#include "AES.hpp"
#include "Challenger.hpp"

#include <fstream>
#include <iostream>


Challenger::Challenger() :
    socket_enviroment(),
    communicator(SERVER_IP, SERVER_PORT),
    iv_manager(),
    message_decryptor(),
    directioning_strings_decryptor()
{}

void Challenger::run_challenge()
{
    Buffer key_digits = communicator.get_key_from_server();
    iv_manager.modify_iv(key_digits);
    execute_digits(key_digits);
    InitialVectorType iv = iv_manager.get_initial_vector();

    Buffer decrypted_message = message_decryptor.decrypt_message(iv, key_digits);

    std::ofstream f("DecryptedMessage.txt", std::ios::binary); // TODO wrap nicely
    f.write(reinterpret_cast<char*>(decrypted_message.data()), decrypted_message.size());
}

void Challenger::execute_digits(const Buffer& key_digits)
{
    for (size_t i = 0; i < key_digits.size() - 1; i+=2)
    {
        iv_manager.modify_iv(key_digits.at(i));
        iv_manager.modify_iv(key_digits.at(i + 1));
        uint8_t entire_byte = (key_digits.at(i) * 10) + key_digits.at(i + 1);
        std::cout << directioning_strings_decryptor.decrypt_directioning_string(i/2, entire_byte) << std::endl;
    }
}
