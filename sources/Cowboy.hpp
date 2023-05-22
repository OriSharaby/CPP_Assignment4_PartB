#pragma once
#include "Character.hpp"

namespace ariel
{
    class Cowboy : public Character
    {
    private:
        int amountOfBullets;

    public:
        Cowboy(string name, Point location);
        void reload();
        bool hasboolets();
        void shoot(Character *);
        void attack(Character *enemy) override;
        string print() override;
        int getAmountOfBullets()
        {
            return this->amountOfBullets;
        }
        void setAmoutOfBullets(){
            this->amountOfBullets -=1;
        }
    };

}