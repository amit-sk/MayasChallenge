#pragma once

#include <cstdint>
#include <array>
#include "Buffer.hpp"
#include "File.hpp"
#include "AES.hpp"

class MessageDecryptor final
{
private:
    static constexpr char MESSAGE_FILE_NAME[] = "Message.txt";

public:
    MessageDecryptor();
    virtual ~MessageDecryptor() = default;

    Buffer decrypt_message(InitialVectorType& iv, Buffer& key);
    Buffer decrypt_directioning_string(size_t index, uint8_t key);
    Buffer encrypt_diretioning_string(size_t index, uint8_t key);

private:
    Buffer read_message();
    Buffer decrypt_message(Buffer& message, InitialVectorType& iv, std::array<unsigned char, 16>& key);

    Buffer& get_directioning_string(size_t index);
    static std::vector<Buffer> get_directioning_strings();

private:
    AES decryptor;
    File message_file;
    std::vector<Buffer> directioning_strings;
};

