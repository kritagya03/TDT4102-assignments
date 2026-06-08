#include "std_lib_facilities.h"
#include "O3.h"

void CourseCatalog::addCourse(){
    string kode;
    cout << "What is the subject code? ";
    getline(cin, kode);

    string title;
    cout << "What is the subject title? ";
    getline(cin,title);

    if (myMap.find(kode) != myMap.end()){
        cout << "This code already exists, but the title will be changed\n";
        //myMap.insert({kode,title});  suposed to do nothing?
        myMap.at(kode)=title;
    } else {
        myMap.insert({kode,title});
    }
}

void CourseCatalog::removeCourse(){
    string kode;
    cout << "What subject code would you like to remove? ";
    cin >> kode;

    if (myMap.find(kode) == myMap.end()){
        cout << "The code does not exists";
    } else {
        myMap.erase(kode);
        cout << "Removed!";
    }
}

void CourseCatalog::getCourse(string kode){
    if (myMap.find(kode) == myMap.end()){
        cout << "There is no subject code of this name";
    } else{
        cout << myMap.at(kode);
    }
}

ostream& operator<<(ostream& os, CourseCatalog c){
    for (pair<string, string> pir: c.myMap){
        os << pir.first <<", " <<c.myMap.at(pir.first) <<endl;
    }
    return os;
}

void CourseCatalog::testFunction(CourseCatalog c){
    c.addCourse();
    c.addCourse();
    cout << c;
}



void CourseCatalog::addToFile(){
    filesystem::path filename="SavedSubjects.csv";
    ofstream output(filename, ios::app);

    string AStr;
    for (pair<string, string> pir: myMap){      //Going through every line of map
        ifstream input(filename);
        string save = pir.first + ", " + pir.second;
        bool check=true;

        while(getline(input,AStr)){     //Going throught every line of file
            if (save==AStr){
                check=false;
            }
        }
        
        if (check){
            output << "\n" + pir.first + ", " + pir.second;
        }
    }
}

void CourseCatalog::readFromFile(){
    filesystem::path filename="SavedSubjects.csv";
    ifstream input(filename);

    string save;
    while (getline(input,save)){
        cout << save <<endl;
    }
}