#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "card.hpp"
#include "deck.hpp"

class Game
{
public:
    Game(Player * player, Player * dealer);
    ~Game();

    void Play();

private:
    Player * m_player;
    Player * m_dealer;

    Deck * m_deck;

    bool m_is_playing;
    bool m_player_stand;
    bool m_dealer_stand;

    //functions
    void Initialize(); //will set points to 0
    void Hit(Player * current); //gives the player a card and adds to points
};

#endif