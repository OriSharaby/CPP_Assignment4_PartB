#include "Cowboy.hpp"
#include "Character.hpp"
#include <string>
#include <iostream>
using namespace std;
namespace ariel
{

    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), amountOfBullets(6) {}

    bool Cowboy::hasboolets()
    {
        if (this->amountOfBullets > 0)
        {
            return true;
        }
        return false;
    }

    void Cowboy::reload()
    {
        if (!this->isAlive())
        {
            throw runtime_error("Cowboy is not alive");
        }
        this->amountOfBullets = 6;
    }

    void Cowboy::shoot(Character *target)
    {
        if (!this->isAlive())
        {
            throw runtime_error("Cowboy is not alive");
        }
        if (!target->isAlive())
        {
            throw runtime_error("Target is not alive");
        }
        if (this == target)
            throw runtime_error("Cannot attack itself");
        if (this->hasboolets())
        {
            target->hit(10);
            setAmoutOfBullets();
        }
    }

    void Cowboy::attack(Character *enemy)
    {
        if (!isAlive() || !enemy->isAlive())
            return;
        if (hasboolets())
            shoot(enemy);
        else
            reload();
    }

    string Cowboy ::print()
    {
        string nameStr = "C: The Character name is :" + this->getName();
        string locationStr = "his location is :" + this->getLocation().print();
        string healthStr = "he has a " + to_string(this->getHealth()) + "hit points";
        if (!isAlive())
        {
            nameStr = "C: The Character name is : (" + this->getName() + " )";
            string healthStr = "";
        }
        return (nameStr + locationStr + healthStr);
    }
}