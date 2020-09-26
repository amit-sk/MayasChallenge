#pragma once

#include <string>
#include <fstream>
#include <filesystem>
#include "Buffer.hpp"

class File
{
public:
    explicit File(const std::string& _path, std::ios_base::openmode mode);
    virtual ~File() = default;

    Buffer read(size_t);
    void write(const Buffer&);
    size_t get_file_size() const;

private:
    std::filesystem::path path;
    std::fstream file_stream;
};

