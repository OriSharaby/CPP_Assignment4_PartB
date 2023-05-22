#pragma once
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

namespace ariel
{
    class Team
    {
    private:
        vector<Character *> team;
        Character *leader;

    public:
        Team(Character *leader);
        Team(const Team &);
        Team(Team &&) noexcept;
        virtual ~Team(){};
        Team &operator=(const Team &);
        Team &operator=(Team &&) noexcept;

        int stillAlive();
        virtual void add(Character *);
        void attack(Team *);
        void print() const;
        Character *closestMember(vector<Character *> &, const Point &);

        Character *getLeader()
        {
            return this->leader;
        }
        vector<Character *> &getTeam()
        {
            return team;
        }
    };

}