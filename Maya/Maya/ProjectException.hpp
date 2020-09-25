#pragma once

#include <cstdint>
#include <string>
#include <type_traits>

enum class ProjectStatus : uint32_t
{
    Success = 0,
    StandardExceptionThrown,
    UnknownExceptionThrown,
    NonAsciiCharacterInputted,
};

class ProjectException
{
public:
    explicit ProjectException(ProjectStatus _status) : 
        status(_status)
    {}

    virtual ~ProjectException() = default;

    std::string get_string_status() const { return std::to_string(static_cast<uint32_t>(status)); }

public:
    ProjectStatus status;
};

