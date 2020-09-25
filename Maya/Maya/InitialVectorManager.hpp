#pragma once

#include <array>
#include <map>
#include <functional>
#include "Buffer.hpp"

class InitialVectorManager
{
public:
    InitialVectorManager();
    virtual ~InitialVectorManager() = default;

    void modify_iv(Buffer modifiers);

    std::array<uint8_t, 16> get_initial_vector() const;

private:
    std::map<uint8_t, std::function<void>()> get_modifiers() const;

private:
    std::array<uint8_t, 16> initial_vector;
    std::map<uint8_t, std::function<void>()> modifiers;
};

