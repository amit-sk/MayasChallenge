#pragma once

#include "Buffer.hpp"

class Halt final
{
public:
    Halt() = default;
    virtual ~Halt() = default;
};

namespace Modifiers
{
    void zero(InitialVectorType&);
    void one(InitialVectorType&);
    void two(InitialVectorType&);
    void three(InitialVectorType&);
    void four(InitialVectorType&);
    void five(InitialVectorType&);
    void six(InitialVectorType&);
    void seven(InitialVectorType&);
    void eight(InitialVectorType&);
    void nine(InitialVectorType&);
};

