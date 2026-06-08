#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "Car.h"

class Person{
private:
    std::string name;
    std::string email;
    std::unique_ptr<Car> CarPointer;

public:
    Person(std::string n, std::string e, std::unique_ptr<Car> car=nullptr);
    std::string getEmail();
    std::string getName();
    void setEmail(std::string value);
    bool hasAvailableSeats();
    
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};