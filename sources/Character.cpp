#include <iostream>
#include <string>
#include <stdexcept>
#include "Character.hpp"
#include "Ninja.hpp"
#include "Cowboy.hpp"
using namespace std;
namespace ariel
{

    Character::Character(const string &name, const Point &location, int health) : name(name), location(location), health(health), inTeam(false) {}

    Character::Character(const Character &other) : name(other.name), location(other.location), health(other.health), inTeam(other.inTeam) {}

    Character::Character(Character &&other) noexcept : name(other.name), location(other.location), health(other.health), inTeam(other.inTeam) {}

    Character &Character::operator=(const Character &other)
    {
        if (this == &other)
            return *this;

        name = other.name;
        location = other.location;
        health = other.health;
        inTeam = other.inTeam;

        return *this;
    }

    Character &Character::operator=(Character &&other) noexcept
    {
        if (this == &other)
            return *this;

        name = move(other.name);
        location = move(other.location);
        health = other.health;
        inTeam = other.inTeam;

        return *this;
    }

    bool Character::isAlive()
    {
        return (this->health > 0);
    }

    double Character::distance(Character *other)
    {
        if (other == nullptr)
        {
            throw invalid_argument("Can't Put null as character!");
        }
        Point otherPoint = other->getLocation();
        return this->getLocation().distance(otherPoint);
    }

    void Character::hit(int damage)
    {
        if (damage < 0)
        {
            throw invalid_argument("hits  cant be < 0");
        }
        if ((this->health - damage) < 0)
        {
            this->health = 0;
        }
        health -= damage;
    }
}