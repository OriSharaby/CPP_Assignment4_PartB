#include "Team2.hpp"
using namespace std;
#include <vector>

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
    }

    void Team2::add(Character *newChar)
    {
        if (newChar != nullptr && newChar->isAlive() && !newChar->getInTeam() && getTeam().size() < 10)
        {
            getTeam().push_back(newChar);
            newChar->setInTeam(true);
        }
        else
        {
            throw runtime_error("Can't add this Character!");
        }
    }
}