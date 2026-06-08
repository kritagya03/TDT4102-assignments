#pragma once
#include "std_lib_facilities.h"

class CourseCatalog{
private:
    unordered_map <string,string> myMap{
        {"TDT4102","Prosedyre- og objekt-orientert programmering"},
    };
public:
    void addCourse();
    void removeCourse();
    void getCourse(string kode);
    friend ostream& operator<< (ostream& os, CourseCatalog c);
    void testFunction(CourseCatalog c);
    void addToFile();
    void readFromFile();
};