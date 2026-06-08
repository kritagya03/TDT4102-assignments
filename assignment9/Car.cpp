#include "Car.h"

Car::Car(int nFreeSeats){
    freeSeats=nFreeSeats;
}

bool Car::hasFreeSeats() const{
    if (freeSeats==0){
        return false;
    } else{
        return true;
    }
}

void Car::reverseFreeSeat(){
    freeSeats--;
}