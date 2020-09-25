#pragma once

#include <map>
#include <functional>
#include "Buffer.hpp"

class InitialVectorManager
{
public:
    InitialVectorManager();
    virtual ~InitialVectorManager() = default;

    void modify_iv(Buffer modifiers);

    InitialVectorType  get_initial_vector() const;

private:
    std::map<uint8_t, std::function<void(InitialVectorType&)>> get_modifiers() const;

private:
    InitialVectorType initial_vector;
    std::map<uint8_t, std::function<void(InitialVectorType&)>> modifiers;
};

