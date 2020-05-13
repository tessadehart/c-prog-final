#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include "deck.hpp"

Deck::Deck()
{
    this->m_cards = new std::vector<Card *>();

    //Hearts
    this->m_cards->push_back(new Card("Hearts", "Ace", 11));
    this->m_cards->push_back(new Card("Hearts", "Two", 2));
    this->m_cards->push_back(new Card("Hearts", "Three", 3));
    this->m_cards->push_back(new Card("Hearts", "Four", 4));
    this->m_cards->push_back(new Card("Hearts", "Five", 5));
    this->m_cards->push_back(new Card("Hearts", "Six", 6));
    this->m_cards->push_back(new Card("Hearts", "Seven", 7));
    this->m_cards->push_back(new Card("Hearts", "Eight", 8));
    this->m_cards->push_back(new Card("Hearts", "Nine", 9));
    this->m_cards->push_back(new Card("Hearts", "Ten", 10));
    this->m_cards->push_back(new Card("Hearts", "Jack", 10));
    this->m_cards->push_back(new Card("Hearts", "Queen", 10));
    this->m_cards->push_back(new Card("Hearts", "King", 10));

    //Spades
    this->m_cards->push_back(new Card("Spades", "Ace", 11));
    this->m_cards->push_back(new Card("Spades", "Two", 2));
    this->m_cards->push_back(new Card("Spades", "Three", 3));
    this->m_cards->push_back(new Card("Spades", "Four", 4));
    this->m_cards->push_back(new Card("Spades", "Five", 5));
    this->m_cards->push_back(new Card("Spades", "Six", 6));
    this->m_cards->push_back(new Card("Spades", "Seven", 7));
    this->m_cards->push_back(new Card("Spades", "Eight", 8));
    this->m_cards->push_back(new Card("Spades", "Nine", 9));
    this->m_cards->push_back(new Card("Spades", "Ten", 10));
    this->m_cards->push_back(new Card("Spades", "Jack", 10));
    this->m_cards->push_back(new Card("Spades", "Queen", 10));
    this->m_cards->push_back(new Card("Spades", "King", 10));

    //Diamonds
    this->m_cards->push_back(new Card("Diamonds", "Ace", 11));
    this->m_cards->push_back(new Card("Diamonds", "Two", 2));
    this->m_cards->push_back(new Card("Diamonds", "Three", 3));
    this->m_cards->push_back(new Card("Diamonds", "Four", 4));
    this->m_cards->push_back(new Card("Diamonds", "Five", 5));
    this->m_cards->push_back(new Card("Diamonds", "Six", 6));
    this->m_cards->push_back(new Card("Diamonds", "Seven", 7));
    this->m_cards->push_back(new Card("Diamonds", "Eight", 8));
    this->m_cards->push_back(new Card("Diamonds", "Nine", 9));
    this->m_cards->push_back(new Card("Diamonds", "Ten", 10));
    this->m_cards->push_back(new Card("Diamonds", "Jack", 10));
    this->m_cards->push_back(new Card("Diamonds", "Queen", 10));
    this->m_cards->push_back(new Card("Diamonds", "King", 10));

    //Clubs
    this->m_cards->push_back(new Card("Clubs", "Ace", 11));
    this->m_cards->push_back(new Card("Clubs", "Two", 2));
    this->m_cards->push_back(new Card("Clubs", "Three", 3));
    this->m_cards->push_back(new Card("Clubs", "Four", 4));
    this->m_cards->push_back(new Card("Clubs", "Five", 5));
    this->m_cards->push_back(new Card("Clubs", "Six", 6));
    this->m_cards->push_back(new Card("Clubs", "Seven", 7));
    this->m_cards->push_back(new Card("Clubs", "Eight", 8));
    this->m_cards->push_back(new Card("Clubs", "Nine", 9));
    this->m_cards->push_back(new Card("Clubs", "Ten", 10));
    this->m_cards->push_back(new Card("Clubs", "Jack", 10));
    this->m_cards->push_back(new Card("Clubs", "Queen", 10));
    this->m_cards->push_back(new Card("Clubs", "King", 10));
}

Deck::~Deck()
{
    delete this->m_cards;
}

std::vector<Card *> * Deck::get_cards()
{
    this->shuffle();
    return this ->m_cards;
}

void Deck::shuffle()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->m_cards->begin(), this->m_cards->end(), std::default_random_engine(seed));
}