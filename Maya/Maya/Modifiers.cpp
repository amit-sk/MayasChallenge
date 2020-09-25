#include "pch.h"
#include <WinSock2.h>
#include "ProjectException.hpp"
#include "Modifiers.hpp"

void Modifiers::zero(InitialVectorType& iv)
{
    iv[0] /= 0;
}

void Modifiers::one(InitialVectorType& iv)
{
    *reinterpret_cast<uint32_t*>(&iv[1]) += 891792;
}

void Modifiers::two(InitialVectorType& iv)
{
    *reinterpret_cast<uint32_t*>(&iv[1]) = ntohl(iv[1]);
}

void Modifiers::three(InitialVectorType& iv)
{
    if (iv[0] != 0)
    {
        throw ProjectException(ProjectStatus::InitialVectorModifier_3_CheckFailed);
    }

    *reinterpret_cast<uint32_t*>(&iv[1]) = 172394839 % iv[0];
}

void Modifiers::four(InitialVectorType& iv)
{
    *reinterpret_cast<uint32_t*>(&iv[0]) *= 2837530;
}

void Modifiers::five(InitialVectorType& iv)
{
    if (iv[1] == 0)
    {
        throw ProjectException(ProjectStatus::InitialVectorModifier_5_CheckFailed);
    }

    *reinterpret_cast<uint32_t*>(&iv[0]) = ntohl(iv[0]);
}

void Modifiers::six(InitialVectorType& iv)
{
    if (iv[0] == 0)
    {
        throw ProjectException(ProjectStatus::InitialVectorModifier_6_CheckFailed);
    }

    iv[0] -= 0x50;
}

void Modifiers::seven(InitialVectorType& iv)
{
    if (*reinterpret_cast<uint32_t*>(&iv[0]) % 2 != 0)
    {
        throw ProjectException(ProjectStatus::InitialVectorModifier_7_CheckFailed);
    }
    *reinterpret_cast<uint32_t*>(&iv[0]) += 0x501F8;
}

void Modifiers::eight(InitialVectorType& iv)
{
    if (iv[1] == 0)
    {
        throw ProjectException(ProjectStatus::InitialVectorModifier_8_CheckFailed);
    }
    iv[0] /= iv[1];
}

void Modifiers::nine(InitialVectorType& iv)
{
    *reinterpret_cast<uint32_t*>(&iv[0]) ^= 0x2155db43;
    throw Halt();
}
