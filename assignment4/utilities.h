#include "std_lib_facilities.h"
#pragma once

int incrementByValueNumTimes(int startValue, int increment, int numTimes);

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);

void swapNumbers(int& firstValue, int& secondValue);

struct Student {
    string name;
    string studyProgram;
    int age;
};

void printStudent(Student student);

bool isInProgram(Student student, string studie);

string randomizeString(int antallTegn, char ovringGrense, char nedreGrense);

string readInputToString(int antallTegn, char ovringGrense, char nedreGrense);

int countChar(string String, char Char);