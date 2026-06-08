#pragma once

class Car{
private:
    int freeSeats;

public:
    Car(int nFreeSeats);
    bool hasFreeSeats() const;
    void reverseFreeSeat();
};
