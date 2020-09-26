#pragma once

#include <cstdint>
#include <vector>
#include "Buffer.hpp"

class DirectioningStringsDecryptor final
{
public:
    DirectioningStringsDecryptor();
    virtual ~DirectioningStringsDecryptor() = default;

    Buffer get_directioning_string(size_t index);
    Buffer encrypt_directioning_string(size_t index, uint8_t key);// const; TODO remove
    Buffer decrypt_directioning_string(size_t index, uint8_t key);// const;

private:
    static std::vector<Buffer> get_directioning_strings();

private:
    std::vector<Buffer> directioning_strings;
};

