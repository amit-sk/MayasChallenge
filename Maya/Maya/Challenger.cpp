#include "pch.h"
#include "File.hpp"
#include "AES.hpp"
#include "Challenger.hpp"
#include "Modifiers.hpp"

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
    execute_digits(key_digits);

    InitialVectorType iv = iv_manager.get_initial_vector();
    Buffer decrypted_message = message_decryptor.decrypt_message(iv, key_digits);

    File message_file("DecryptedMessage.txt", std::ios::out | std::ios::binary);
    message_file.write(decrypted_message);
}

void Challenger::execute_digits(const Buffer& key_digits)
{
    try
    {
        for (size_t i = 0; i < key_digits.size() - 1; i+=2)
        {
            uint8_t first_digit = key_digits.at(i);
            uint8_t second_digit = key_digits.at(i + 1);
            uint8_t entire_byte = (first_digit * 10) + second_digit;

            std::cout << directioning_strings_decryptor.encrypt_directioning_string(i/2, entire_byte) << std::endl; // TODO remove
            std::cout << directioning_strings_decryptor.decrypt_directioning_string(i/2, entire_byte) << std::endl;
            //iv_manager.modify_iv(first_digit);
            //iv_manager.modify_iv(second_digit);
        }
    }
    catch (const Halt& _)
    {}
}
