#include "pch.h"
#include <algorithm>
#include "Modifiers.hpp"
#include "InitialVectorManager.hpp"

InitialVectorManager::InitialVectorManager() :
    initial_vector(),
    modifiers(get_modifiers())
{
    initial_vector.fill(0);
}

std::map<uint8_t, std::function<void(InitialVectorType&)>> InitialVectorManager::get_modifiers() const
{
    return std::map<uint8_t, std::function<void(InitialVectorType&)>>{
        {0, Modifiers::zero},
        {1, Modifiers::one},
        {2, Modifiers::two},
        {3, Modifiers::three},
        {4, Modifiers::four},
        {5, Modifiers::five},
        {6, Modifiers::six},
        {7, Modifiers::seven},
        {8, Modifiers::eight},
        {9, Modifiers::nine}
    };
}

InitialVectorType InitialVectorManager::get_initial_vector() const
{
    return initial_vector;
}

void InitialVectorManager::modify_iv(uint8_t modifier)
{
    modifiers.at(modifier)(initial_vector);
}

void InitialVectorManager::modify_iv(Buffer modifiers)
{
    try
    {
        std::for_each(
            modifiers.begin(),
            modifiers.end(),
            [this](uint8_t digit) { this->modifiers.at(digit)(this->initial_vector); }
        );
    }
    catch (const Halt& _)
    {}
}
