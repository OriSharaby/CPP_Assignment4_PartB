#pragma once
#include "Character.hpp"

using namespace std;

constexpr int Y_NINJA_HP = 100;
constexpr int Y_NINJA_SPEED= 14;
constexpr int T_NINJA_HP =120;
constexpr int T_NINJA_SPEED =12;
constexpr int O_NINJA_HP= 150;
constexpr int O_NINJA_SPEED =8;

namespace ariel
{
    class Ninja : public Character
    {
    private:
        int speed;

    public:
        Ninja(string name, const Point& location, int health, int speed);
        void move(Character *);
        void slash(Character *);
        void attack(Character *) override;
        string print() override;
        int getSpeed()
        {
            return this->speed;
        }
    };


}