#include "CardDeck.h"
#include "Card.h"
#include "std_lib_facilities.h"

CardDeck::CardDeck() {
    for (int i=0;i<=static_cast<int>(Suit::spades);i++){
        for (int j=2;j<=static_cast<int>(Rank::ace);j++){
        Suit suitt=static_cast<Suit>(i);
        Rank rankk=static_cast<Rank>(j);
        Card c{suitt,rankk};
        allCards.push_back(c);
        }
    }
}

void CardDeck::check(int a){
    cout << allCards.at(a).toString();
}

void CardDeck::swap(int index, int index2){
    Card save=allCards.at(index);
    allCards.at(index)=allCards.at(index2);
    allCards.at(index2)=save;
}

void CardDeck::print(){
    for (int i=0;i<allCards.size();i++){
        cout << allCards.at(i).toString() <<endl;
    }
}

void CardDeck::shuffle(){
    for(int i=0;i<allCards.size();i++){
        random_device rd;
        default_random_engine engine(rd());
        uniform_int_distribution<int> distribution(0,allCards.size()-1);
        int random = distribution(engine);

        swap(i,random);
    }
}

Card CardDeck::drawCard(){
    Card save=allCards.at(0);
    allCards.erase(allCards.begin());
    return save;
}


BlackJack::BlackJack(){
    
}


void BlackJack::getPoints(int& points, Card aCard){
    if (static_cast<int>(aCard.returnRank())<=10){
        points+=static_cast<int>(aCard.returnRank());
        }
    else if (static_cast<int>(aCard.returnRank())==14){
        if (points>10){
            points+=1;
        } else {
            points+=11;
        }
    } else{
        points+=10;
    }
}

void BlackJack::dealerMove(int& points, CardDeck Dealercard){
    while (points<17){
        Card Card2Dealer= Dealercard.drawCard();
        cout<< "The dealer draws a ";
        cout << Card2Dealer.toString() << endl;
        getPoints(points, Card2Dealer);
        cout << "The dealer has " << points <<" points\n\n";
    }
}

void BlackJack::checkWin(int player, int dealer){
    cout << "You have " <<player << " points\n";
    cout << "The dealer has " << dealer << " points\n";
    if ((player>21 && dealer>21) || player==dealer){
        cout << "A losing tie";
    } else if (player>21){
        cout << "You lose, Dealer wins :(";
    } else if (dealer>21){
        cout << "Dealer lose, You win!";
    } else if (player>dealer){
        cout << "You win, Dealer lose!";
    } else {
        cout << "Dealer wins, You lose :(";
    }
}


void BlackJack::playBlackJack(){
    CardDeck Cards;
    Cards.shuffle();

    int pointsPlayer=0;
    Card Card1= Cards.drawCard();
    Card Card2= Cards.drawCard();

    cout << "Hello welcome to Blackjack!, here are your card: \n";
    cout << Card1.toString() << endl;
    cout << Card2.toString() << endl;

    getPoints(pointsPlayer, Card1);
    getPoints(pointsPlayer, Card2);
    cout << "You have " << pointsPlayer <<" points\n\n";


    int pointsDealer=0;
    Card Card1Dealer= Cards.drawCard();

    cout << "The Dealer has: \n";
    cout << Card1Dealer.toString() << endl;
    cout << "?" << endl;

    getPoints(pointsDealer, Card1Dealer);
    cout << "The dealer has " << pointsDealer <<" points\n\n";


    int gameOver=0;
    while (gameOver==0){
        if (pointsPlayer>21){
            cout << "Sorry you have more than 21 points, you have to STAND\n\n";
            gameOver=1;
            } 
        else {
            string answer;
            cout << "Would you like to HIT or STAND (H/S)\n";
            cin >> answer;

            if (answer=="S") {
                gameOver=1;
                }
            else {
                Card Card3= Cards.drawCard();
                cout << "You got a " << Card3.toString() << endl;
                getPoints(pointsPlayer, Card3);
                cout << "You have " << pointsPlayer <<" points\n\n";
                }
            }
    }
    
    dealerMove(pointsDealer, Cards);
    checkWin(pointsPlayer,pointsDealer);

    cout << "\nGame Over";
}