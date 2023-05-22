#include "Team.hpp"
#include "Character.hpp"
#include <cfloat>
#include <stdexcept>
#include <vector>
#include <iostream>
using namespace std;
namespace ariel
{

  Team::Team(Character *leader) : leader(leader)
  {
    if (leader->getInTeam())
      throw runtime_error("Leader is already on a team");
    team.push_back(leader);
    leader->setInTeam(true);
  }

  Team::Team(const Team &other) : leader(other.leader) {}

  Team::Team(Team &&other) noexcept
  {
    leader = other.leader;
    team = other.team;
  }

  Team &Team::operator=(const Team &other)
  {
    leader = other.leader;
    team = other.team;
    return *this;
  }

  Team &Team::operator=(Team &&other) noexcept
  {
    leader = other.leader;
    team = other.team;
    return *this;
  }

  void Team::attack(Team *other)
  {
    if (!other)
      throw invalid_argument("enemy is nullptr");

    if (stillAlive() == 0 || other->stillAlive() == 0)
      throw runtime_error("one of the team dead");

    if (!leader->isAlive())
      leader = closestMember(this->team, leader->getLocation());

    Character *target = nullptr;

    if (other->stillAlive() > 0)
      target = closestMember(other->team, leader->getLocation());
    else
      return;

    for (auto member : team)
    {
      if (member != nullptr && member->isAlive())
      {
        if (target != nullptr && target->isAlive())
        {
          member->attack(target);
        }
        else
        {
          target = closestMember(other->team, leader->getLocation());
          if (target != nullptr && target->isAlive())
          {
            member->attack(target);
          }
        }
      }
    }
  }

  void Team::add(Character *newChar)
  {
    if (newChar != nullptr && newChar->isAlive() && !newChar->getInTeam() && team.size() < 10)
    {
      if (dynamic_cast<Cowboy *>(newChar) != nullptr)
        team.insert(team.begin(), newChar);
      else
        team.push_back(newChar);
      newChar->setInTeam(true);
    }
    else
    {
      throw runtime_error("Can't add this Character!");
    }
  }

  int Team::stillAlive()
  {
    int counter = 0;
    for (Character *member : team)
      if (member->isAlive())
        counter++;
    return counter;
  }

  Character *Team::closestMember(vector<Character *> &other, const Point &)
  {
    double minDistance = DBL_MAX;
    Character *result = NULL;
    for (Character *member : other)
      if (member->isAlive() && leader->distance(member) < minDistance)
      {
        minDistance = leader->distance(member);
        result = member;
      }
    return result;
  }

  void Team::print() const
  {
    for (Character *member : team)
      cout << member->print() << endl;
  }
}