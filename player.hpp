#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "card.hpp"
#include <string>

struct Player
{
    Player(std::string name, int points);
    std::string name;
    int points;
};

#endif