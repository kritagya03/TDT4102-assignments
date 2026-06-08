#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include "Person.h"

enum class Campus{
    Trondheim,
    AAlesund,
    Gjøvik
};

class Meeting{
private:
    int day;
    int startTime;
    int endTime;
    Campus location;
    std::string subject;
    const std::shared_ptr<Person> leader;
    std::vector <std::shared_ptr<Person>> participants;

public:
    int getDay();
    int getStartTime();
    int getEndTime();
    Campus getLocation();
    std::string getSubject();
    std::string getLeader();

    Meeting(int d, int s, int e, Campus l, std::string sub, 
    std::shared_ptr<Person> lea);
    void addParticipant(std::shared_ptr<Person> person);
    std::vector<std::string> getParticipantList();
    std::vector<std::shared_ptr<Person>> findPotentialCoDriving(Meeting m);
};

std::ostream& operator<<(std::ostream& os, Meeting& m);