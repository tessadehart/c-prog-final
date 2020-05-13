#ifndef CARD_HPP
#define CARD_HPP

#include <string>
struct Card
{
    Card(std::string suit, std::string num, int value);
    std::string suit;
    std::string num;
    int value;
};

#endif