#pragma once

#include <cstdint>
#include <string>
#include <exception>

enum class ProjectStatus : uint32_t
{
    Success = 0,
    StandardExceptionThrown,
    UnknownExceptionThrown,
};

class ProjectException : public std::exception
{
public:
    ProjectException(ProjectStatus _status) : 
        status(_status)
    {}

    virtual ~ProjectException() = default;

    std::string get_string_status() const { return std::to_string(static_cast<uint32_t>(status)); }

public:
    ProjectStatus status;
};

