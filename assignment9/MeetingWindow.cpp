#include "MeetingWindow.h"
#include "Person.h"
#include "AnimationWindow.h"

MeetingWindow::MeetingWindow(int x, int y, int w, int h, const std::string& title) : 
TDT4102::AnimationWindow (x,y,w,h,title){
    add(quitBtn);
    add(personName);
    add(personEmail);
    add(personNewBtn);
    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));
    personNewBtn.setCallback(std::bind(&MeetingWindow::cb_personName, this));
}

void MeetingWindow::cb_personName(){
    std::string name=personName.getText();
    std::string email=personEmail.getText();
    
    people.emplace_back(new Person(name, email));

    std::cout << people[people.size()-1]->getName();
}

void MeetingWindow::cb_quit(){
    close();
}