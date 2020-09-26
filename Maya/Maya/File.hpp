#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include "Buffer.hpp"

class File
{
public:
    explicit File(const std::string& _path);
    virtual ~File() = default;

    Buffer read(size_t);
    size_t get_file_size() const;

private:
    std::filesystem::path path;
    std::ifstream file_stream;
};

