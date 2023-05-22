#include "Ninja.hpp"
#include "Character.hpp"
#include "Point.hpp"
#include <string>
#include <iostream>
using namespace std;
namespace ariel
{

    Ninja ::Ninja(string name, const Point &location, int health, int speed) : Character(name, location, health), speed(speed) {}

    void Ninja ::move(Character *target)
    {
        if (!isAlive())
        {
            return;
        }
        Point source = this->getLocation();
        Point destination = target->getLocation();
        Point tmp = Point::moveTowards(source, destination, this->getSpeed());
        this->setLocation(tmp);
    }

    void Ninja ::slash(Character *target)
    {
        if (!isAlive())
            throw runtime_error("Ninja is not alive");

        if (!target->isAlive())
            throw runtime_error("Target is not alive");

        if (this == target)
            throw runtime_error("Cannot attack itself");
        if (isAlive() && this->getLocation().distance(target->getLocation()) < 1)
        {
            target->hit(40);
        }
    }

    void Ninja::attack(Character *other)
    {
        if (!isAlive() || !other->isAlive())
            return;
        if (distance(other) <= 1)
            slash(other);
        else
            move(other);
    }

    string Ninja ::print()
    {
        string nameStr = "N: The Character name is :" + this->getName();
        string locationStr = "his location is :" + this->getLocation().print();
        string healthStr = "he has a " + to_string(this->getHealth()) + "hit points";
        if (!isAlive())
        {
            nameStr = "N: The Character name is : (" + this->getName() + " )";
            string healthStr = "";
        }
        return (nameStr + locationStr + healthStr);
    }
}