#include <iostream>
#include "game.hpp"
#include <string>

Game::Game(Player * player, Player * dealer)
{
    this-> m_player = player;
    this-> m_dealer = dealer;
    this-> m_deck = new Deck();
}

Game::~Game()
{
    delete this->m_player;
    delete this->m_dealer;
    delete this->m_deck;
}

void Game::Play()
{
    this->m_is_playing = true;

    while(m_is_playing)
    {
        if(m_player->points > 21)
        {
            this->m_is_playing = false;
            std::cout << "Player Loses/n" << std::endl;
        }
        else if(m_dealer->points > 21)
        {
            this->m_is_playing = false;
            std::cout << "Player Wins/n" << std::endl;
        }
        else
        {
            //Player's turn
            std::cout << "Player, Stand or Hit?/n";
            std::string play;
            std::cin >> play;
            if(play == "hit")
            {
                Hit(m_player);
            }
            else if(play == "stand")
            {
                m_player_stand = true;
                std::cout << "Player stands/n";

                //if both stand the games ends
                if(m_dealer_stand == true)
                {
                    m_is_playing = false;
                    if(m_player->points > m_dealer->points)
                    {
                        std::cout << "Player Wins/n" << std::endl;
                    }
                    else if(m_player->points < m_dealer->points)
                    {
                        std::cout << "Player Loses/n" << std::endl;
                    }
                    else
                    {
                        std::cout << "Tie/n" << std::endl;
                    }
                }
            }
            else
            {
                std::cout << "Please enter 'stand' or 'hit/n'";
                Play();
            }
            //Dealer's turn
            if(m_dealer->points >= 17)
            {
                m_dealer_stand = true;
                std::cout << "Dealer stands/n";

                //if both stand the games ends
                if(m_player_stand == true)
                {
                    m_is_playing = false;
                    if(m_player->points > m_dealer->points)
                    {
                        std::cout << "Player Wins/n" << std::endl;
                    }
                    else if(m_player->points < m_dealer->points)
                    {
                        std::cout << "Player Loses/n" << std::endl;
                    }
                    else
                    {
                        std::cout << "Tie/n" << std::endl;
                    }
                    
                }
            }
            else
            {
                Hit(m_dealer);
            }
            
        }
        
    }
}

void Game::Initialize()
{
    m_player->points = 0;
    m_player->name = "Player";
    m_dealer->points = 0;
    m_dealer->name = "Dealer";
}

void Game::Hit(Player * current)
{
    int x;
    Card *card = this->m_deck->get_cards()->at(x);
    current->points += card->value;
    std::cout << current->name << " recieves " << card->num << " of " <<card->suit;
}