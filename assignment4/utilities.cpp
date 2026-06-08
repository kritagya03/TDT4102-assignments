#include "utilities.h"
#include "std_lib_facilities.h"

int incrementByValueNumTimes(int startValue, int increment, int numTimes){
    for (int i=0; i< numTimes; i++){
        startValue+=increment;
    }
    return startValue;
}

int incrementByValueNumTimesRef(int& startValue, int increment, int numTimes){
    for (int i=0; i< numTimes; i++){
        startValue+=increment;
    }
    return startValue;
}

void swapNumbers(int& firstValue, int& secondValue){
    int save=firstValue;
    firstValue=secondValue;
    secondValue=save;
}

void printStudent(Student student){ 
    cout << "The name of the student: " <<student.name <<endl;
    cout << "The study program of the studend: " <<student.studyProgram <<endl;
    cout << "The age of the student is: "<<student.age << endl;
}

bool isInProgram(Student student, string studie) {
    if (studie==student.studyProgram) {
        return true;
    } else {
        return false;
    }
    return false;
}

string randomizeString(int antallTegn, char ovringGrense, char nedreGrense){
    string empty="";
    random_device rd;
    default_random_engine generator(rd());

    int lowerLimit = int(nedreGrense);
    int upperLimit = int(ovringGrense);

    uniform_int_distribution<int> distribution (lowerLimit,upperLimit);

    for (int i=0; i<antallTegn; i++){
        empty+=char(distribution(generator));
    }

    return empty;
}

string readInputToString(int antallTegn, char ovringGrense, char nedreGrense){
    string empty="";
    while (empty.size()<antallTegn){
        char letter;
        cout << "Write a letter: ";
        cin >> letter;
        letter= toupper(letter);
        if (letter>ovringGrense || letter<nedreGrense){
            cout << "Not within range\n";
        } else {
            empty +=letter;
            cout << empty <<endl;
        }
    }
    return empty;
}

int countChar(string String, char Char){
    int result=0;
    for (int i=0;i<String.size();i++){
        if (String.at(i)==Char){
            result+=1;
        }
    }
    return result;
}

