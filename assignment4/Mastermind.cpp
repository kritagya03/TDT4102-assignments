#include "Mastermind.h"
#include "utilities.h"
#include "std_lib_facilities.h"

void Mastermind(){
    constexpr int size=4;
    constexpr int letters=6;
    string code;
    string guess="   ";
    
    int lives=10;
    int gameOver=0;
    while (gameOver==0){
        code=randomizeString(size, 'A'+(letters-1),'A');
        cout << code << endl;
        while (checkCharactersAndPosition(code,guess) != 4 && lives!=0) {
            cout << "You have " << lives << " lives left\n";
            guess=readInputToString(size, 'A'+(letters-1), 'A');

            cout << "You have " << checkCharactersAndPosition(code, guess)
            << " letters in the correct position\n";
            cout << "You guessed " << checkCharacters(code, guess) 
            << " letters correctly\n";
            lives-=1;
            }

    string answer;
    if (checkCharactersAndPosition(code,guess) == 4){
        cout << "Congratulations! Would you like to play again?(Y/N) ";
        cin >> answer;
        } else {
        cout << "You lost :(. Would you like to play again?(Y/N) ";
        cin >> answer;
        }

    if (answer=="N"){
        gameOver=1;
    } else {
        guess="    ";
        lives=10;
    }
    }
}


int checkCharactersAndPosition(string code, string guess) {
    int result=0;
    for (int i=0;i<code.size();i++){
        if (code.at(i)==guess.at(i)){
            result+=1;
        }
    }
    return result;
}

int checkCharacters(string code, string guess){
    int result=0;
    for (int i=0;i<code.size();i++){
        for (int j=0;j<code.size();j++){
            if (guess.at(i)==code.at(j)){
                result+=1;
                break;
            }
        }
    }
    return result;
}