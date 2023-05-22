#pragma once
#include "Ninja.hpp"
namespace ariel
{
    class OldNinja : public Ninja
    {
    public:
        OldNinja(string name, const Point &location) : Ninja(std::move(name), location, O_NINJA_HP, O_NINJA_SPEED) {}
    };
}
