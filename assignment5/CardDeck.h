#pragma once
#include "std_lib_facilities.h"
#include "Card.h"

class CardDeck{
private:
    vector<Card> allCards={};
public:
    CardDeck();
    void check(int a);
    void swap(int index, int index2);
    void print();
    void shuffle();
    Card drawCard();
};

class BlackJack{
private:
    //int dontKnoWhatThisIsFor=0;
public:
    BlackJack();
    void playBlackJack();
    void dealerMove(int& points, CardDeck Dealercard);
    void checkWin(int player, int dealer);
    void getPoints(int& points, Card aCard);
};