#include "Stopwatch.h"
#include "optimizationTask.h"
#include "array.h"
#include <iostream>
#include <memory>
#include <vector>
#include <random>
#include <algorithm>
#include <string>


template<typename T>
T maximum(T one, T two){
    if (one>two){
        return one;
    } else {
        return two;
    }
}

template<typename U> //hvorfor funker ikke???
std::vector<U> shuffle (std::vector<U> deck) {
    std::random_device rd;
    std::default_random_engine engine(rd());
    
    std::shuffle(deck.begin(),deck.end(),engine);

    return deck;
}

int main() {

    MyArray<int, 5> array;
    std::cout << array.getSize() <<"\n";
    

    std::vector<int> a{1, 2, 3, 4, 5, 6, 7};
    for (int i=0;i<a.size();i++){
        std::cout << shuffle<int>(a)[i] << std::endl; // Resultat, rekkefølgen i a er endret.
    }

    Stopwatch stopwatch;
    stopwatch.start();

    for (int i=0;i<1;i++){
        optimizationTask();
    }
    std::cout << stopwatch.stop()/1 <<std::endl;

    return 0;
}

//------------------------------------------------------------------------------
