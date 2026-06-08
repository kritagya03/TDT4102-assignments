#include "std_lib_facilities.h"
#include "O3.h"
#include "bouncingBall.h"

void WriteToFile(filesystem::path fileName){
    cout << "Write a message to your file! ";
    string message;
    getline(cin,message);
    ofstream output(fileName/*, ios::app*/);
    
    while (message!="quit"){
        //cout<< message;
        output << message <<"\n";

        cout << "Keep writing messages to your file! ";
        getline(cin,message);
    }
    cout << "All done!";
}


void readThenWrite(filesystem::path toRead, filesystem::path toWrite){
    ifstream inflow(toRead);
    ofstream outflow(toWrite);
    string line;
    int lineCounter=1;

    if (!inflow) {
        cout << "no file could be found" <<endl;
    }else{
        while (getline(inflow, line)){
            outflow << lineCounter << " " << line << "\n";
            lineCounter++;
            }

    }
}


int main() {
    filesystem::path config_file{"konfigurasjon.txt"};
    Config BallInfo;
    for (int i=0;i<3;i++){
        ifstream is{config_file};
        is >> BallInfo;
        cout <<BallInfo.ColorUp << endl;
    }

    bouncingBall();
    /*
    CourseCatalog c;
    c.addCourse();
    c.addCourse();
    c.addToFile();
    c.readFromFile();
    */
    return 0;
}
