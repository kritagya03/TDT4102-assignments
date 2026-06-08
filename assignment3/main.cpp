#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.h"

void testDeviation(double compareOperand, double toOperand,
double maxError, string name){
    if (abs(compareOperand-toOperand)<= maxError){
        cout << name << " is less than maxError" <<endl;
    } else{
        cout <<name << " is larger than maxError" <<endl;
    }
}

int main() {
    cout << "Hello, World!" << endl;
    playTargetPractice();

    return 0;
}

//------------------------------------------------------------------------------
