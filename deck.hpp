#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "card.hpp"

class Deck
{
private:
    std::vector<Card *> * m_cards;

    void shuffle();

public:
    Deck();
    ~Deck();
    std::vector<Card *> * get_cards();
};

#endif