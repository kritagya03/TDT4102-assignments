#include "tests.h"
#include "utilities.h"
#include "std_lib_facilities.h"

void testCallByValue(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
        cout << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << result << endl;
}

void testCallByReference(){
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimesRef(v0, increment, iterations);
        cout << "v0: " << v0
        << " increment: " << increment
        << " iterations: " << iterations
        << " result: " << result << endl;
}

void testString(){
    string grades=randomizeString(8, 'F', 'A');
    cout << grades;

    vector<int> gradesCount ={'A','B','C','D','E','F'};
    vector<int> gradesHowMany ={};
    for(int i=0; i<gradesCount.size(); i++){
        int result=countChar(grades, gradesCount.at(i));
        gradesHowMany.push_back(result);
    }
    int multiply=6;
    int answer=0;
    for(int i=0; i<gradesHowMany.size(); i++) {
        answer+=gradesHowMany.at(i)*multiply;
        multiply-=1;
    }

    cout << "\nThe mean grade: " << answer/8.0;
}

//Opprett en vector med heltall, 
//gradeCount, i testString(). Den skal romme 
//antall forekomster av hver karakter (A-F).