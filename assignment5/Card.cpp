#include "Card.h"
#include "std_lib_facilities.h"

string suitToString(Suit value){
    switch(value){
        case Suit::clubs:
            return "Clubs";
        case Suit::diamonds:
            return "Diamonds";
        case Suit::hearts:
            return "Hearts";
        case Suit::spades:
            return "Spades";
    }
    return "No Value";
}

//But why??
string rankToString(Rank value){
    unordered_map<Rank, string> Map{
    {Rank::two, "Two"},
    {Rank::three, "Three"},
    {Rank::four, "Four"},
    {Rank::five, "Five"},
    {Rank::six, "Six"},
    {Rank::seven, "Seven"},
    {Rank::eight, "Eight"},
    {Rank::nine, "Nine"},
    {Rank::ten, "Ten"},
    {Rank::jack, "Jack"},
    {Rank::queen, "Queen"},
    {Rank::king, "King"},
    {Rank::ace, "Ace"}
    };

    return Map.at(value);
}

Card::Card(Suit suit, Rank rank){
    s=suit;
    r=rank;
}

string Card::getSuit(){
    return suitToString(s);
}

string Card::getRank(){
    return rankToString(r);
}

Rank Card::returnRank(){
    return r;
}

string Card::toString(){
    return getRank() + " Of " + getSuit();
}