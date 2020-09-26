#include "pch.h"
#include <system_error>
#include "File.hpp"


File::File(const std::string& _path) :
    path(_path),
    file_stream(path, std::ios::binary)
{
    if (!file_stream.is_open())
    {
        throw std::system_error(std::error_code(errno, std::system_category()), "Failed to open file.");
    }
    file_stream.exceptions(std::ifstream::failbit);
}

size_t File::get_file_size() const
{
    return static_cast<size_t>(std::filesystem::file_size(path));
}

Buffer File::read(size_t bytes_to_read)
{
    Buffer result(bytes_to_read);
    file_stream.read(reinterpret_cast<char*>(result.data()), result.size());
    return result;
}
