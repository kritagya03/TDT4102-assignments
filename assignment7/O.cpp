#include "std_lib_facilities.h"
#include "O.h"

Animal::Animal(string n, int a){
    name=n;
    age=a;
}

string Animal::toString(){
    return "Animal: "+ name +" "+ to_string(age); 
}

string Cat::toString(){
    return "Cat: " + name +" "+to_string(age);
}

string Dog::toString(){
    return "Dog: " + name +" "+to_string(age);
}

void testfunksjon(){
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(new Cat("Pus",3));
    //animals.emplace_back(new Animal("Giraffe",4));
    cout << animals.at(0) -> toString();
}