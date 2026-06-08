#include <iostream>
#include "Car.h"
#include "Person.h"
#include "Meeting.h"
#include "MeetingWindow.h"
#include <string>
#include <memory>


int main() {



    MeetingWindow m(50,50,1024,768,"Animation Window");

    m.wait_for_close();


    /*
    Car c(2);
    std::unique_ptr<Car> carrr=std::make_unique<Car>(std::move(c));

    Person p("kritt", "kritt.no", std::move(carrr));

    std::cout << p;

    
    std::shared_ptr<Person> per= std::make_shared<Person>("kritti", "kritti.no",
    std::make_unique<Car>(2));


    
    Meeting m(21,9,11,Campus::Trondheim,"Home", per);

    std::cout << m;
    
    
    std::shared_ptr<Person> per2=std::make_shared<Person>("kriti", "kriti.no",
    std::make_unique<Car>(2));
    
    Meeting m2(22,9,11,Campus::Trondheim,"Home", per2);

    std::vector<std::shared_ptr<Person>> y=m.findPotentialCoDriving(m2);
    std::cout << y.size();
    */
    return 0;
}

//------------------------------------------------------------------------------
