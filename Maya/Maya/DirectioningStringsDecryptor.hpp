#pragma once

#include <cstdint>
#include <string>
#include <vector>

class DirectioningStringsDecryptor final
{
public:
    DirectioningStringsDecryptor();
    virtual ~DirectioningStringsDecryptor() = default;

    std::string encrypt_directioning_string(size_t index, uint8_t key);// const; TODO remove
    std::string decrypt_directioning_string(size_t index, uint8_t key);// const;

private:
    static std::vector<std::string> get_directioning_strings();

private:
    std::vector<std::string> directioning_strings;
};

