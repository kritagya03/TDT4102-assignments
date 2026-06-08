#include "Meeting.h"
#include <iostream>
#include <string>
#include <memory>
#include <vector>

std::ostream& operator<<(std::ostream& os, const Campus& c){
    switch (c) {
        case (Campus::Trondheim):
            os << "Trondheim";
            break;
        case (Campus::AAlesund):
            os << "Ålesund";
            break;
        case (Campus::Gjøvik):
            os << "Gjøvik";
            break;
        default:
            os << "Unknown";
            break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, Meeting& m){
    os << "The start time is " << m.getStartTime() <<std::endl;
    os << "The end time is " << m.getEndTime() << std::endl;
    os << "The loation is " << m.getLocation() << std::endl;
    os << "The subject is " << m.getSubject() << std::endl;
    os << "The meeting leader is " <<m.getLeader() << std::endl;
    os << "The meeting participants are " << std::endl;

    std::vector<std::string> people = m.getParticipantList();
    for (int i=0;i<people.size();i++){
        os << "-" << people[i] <<std::endl;
    }

    return os;
}

int Meeting::getDay(){
    return day;
}
int Meeting::getStartTime(){
    return startTime;
}
int Meeting::getEndTime(){
    return endTime;
}
Campus Meeting::getLocation(){
    return location;
}
std::string Meeting::getSubject(){
    return subject;
}
std::string Meeting::getLeader(){
    return leader->getName();
}


Meeting::Meeting(int d, int s, int e, Campus l, std::string sub, 
std::shared_ptr<Person> lea): leader{lea} {
    day=d;
    startTime=s;
    endTime=e;
    location=l;
    subject=sub;
    participants.push_back(lea);
}

void Meeting::addParticipant(std::shared_ptr<Person> person){
     if (person) {
        participants.push_back(person);
    } else {
        std::cerr << "Attempted to add a null person to the meeting\n";
    }
}

std::vector<std::string> Meeting::getParticipantList(){
    std::vector<std::string> people;
    for (int i=0; i<participants.size();i++){
        std::string person= participants[i]->getName();
        people.push_back(person);
    }
    return people;
}

std::vector<std::shared_ptr<Person>> Meeting::findPotentialCoDriving(Meeting m){
    std::vector<std::shared_ptr<Person>> people=m.participants;
    std::vector<std::shared_ptr<Person>> empty;
    for (int i=0;i<people.size();i++){
        if (people[i]->hasAvailableSeats()){
            
            if (this->location==m.location &&
            this->day==m.day &&
            m.startTime-1 < this->startTime < m.startTime+1 &&
            m.endTime-1 < this->endTime < m.endTime+1){
                empty.push_back(people[i]);
            }
        }
    }
    return empty;
}