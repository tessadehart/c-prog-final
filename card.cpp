#include <iostream>
#include "card.hpp"

//constructor
Card::Card(std::string suit, std::string num, int value)
{
    this->suit = suit;
    this->num = num;
    this->value = value;
}