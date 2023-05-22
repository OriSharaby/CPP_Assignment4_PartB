#pragma once
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
    private:
        Point location;
        int health;
        string name;
        bool inTeam;

    public:
        Character(const string &name, const Point &location, int health);
        Character(const Character &other);
        Character(Character &&other) noexcept;
        Character &operator=(const Character &other);
        Character &operator=(Character &&other) noexcept;
        bool isAlive();
        double distance(Character *);
        void hit(int);
        virtual string print() = 0;
        virtual void attack(Character *enemy) = 0;
        bool getInTeam()
        {
            return this->inTeam;
        }
        void setInTeam(bool flag)
        {
            this->inTeam = flag;
        }
        Point getLocation()
        {
            return this->location;
        }
        void setLocation(Point newLocation)
        {
            this->location = newLocation;
        }
        int getHealth()
        {
            return this->health;
        }
        void setHealth(int health)
        {
            this->health = health;
        }
        string getName()
        {
            return this->name;
        }
    };
}