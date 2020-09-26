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

private:
    Buffer read_message();
    Buffer decrypt_message(Buffer& message, InitialVectorType& iv, std::array<unsigned char, 16>& key);

private:
    AES decryptor;
    File message_file;
};

