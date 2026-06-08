#include "Person.h"
#include <string>
#include <memory>
#include <iostream>
#include "Car.h"

Person::Person(std::string n, std::string e, std::unique_ptr<Car> car){
    name=n;
    email=e;
    CarPointer=std::move(car);
}

std::string Person::getEmail(){
    return email;
}

std::string Person::getName() {
    return name;
}

void Person::setEmail(std::string value){
    email=value;
}


bool Person::hasAvailableSeats(){
    if (CarPointer.get()!=nullptr &&
    CarPointer->hasFreeSeats()){
        return true;
    } else{
        return false;
    }
}

std::ostream& operator<<(std::ostream& os, const Person& p){
    os << "The name is: " <<p.name << std::endl;
    os << "The email is: " << p.email << std::endl;
    os << "The car nr. is: " <<p.CarPointer.get() << std::endl;

    return os;
}