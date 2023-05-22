#pragma once
#include "Ninja.hpp"
namespace ariel
{
    class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(string name, const Point &location) : Ninja(std::move(name), location, T_NINJA_HP, T_NINJA_SPEED) {}
    };
}