#include "pch.h"
#include <cstring>
#include <fstream>
#include "Decryptor.hpp"


MessageDecryptor::MessageDecryptor() :
    decryptor(128),
    message_file(MESSAGE_FILE_NAME, std::ios::in | std::ios::binary)
{}

Buffer MessageDecryptor::read_message()
{
    return message_file.read(message_file.get_file_size());
}

Buffer MessageDecryptor::decrypt_message(InitialVectorType& iv, Buffer& key)
{
    Buffer encrypted_message = read_message();

    std::array<unsigned char, 16> used_key;
    used_key.fill(0);

    std::memcpy(used_key.data(), key.data(), std::min<size_t>(used_key.size(), key.size()));

    return decrypt_message(encrypted_message, iv, used_key);
}

Buffer MessageDecryptor::decrypt_message(Buffer& message, InitialVectorType& iv, std::array<unsigned char, 16>& key)
{
    const auto& decrypted_messsage_buffer = decryptor.DecryptCBC(reinterpret_cast<unsigned char*>(message.data()),
                                                                 message.size(),
                                                                 key.data(),
                                                                 reinterpret_cast<unsigned char*>(iv.data()));
    return Buffer(decrypted_messsage_buffer, decrypted_messsage_buffer + message.size());
}
