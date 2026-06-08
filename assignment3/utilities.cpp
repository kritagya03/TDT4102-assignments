#include "std_lib_facilities.h"
#include "utilities.h"

int randomWithLimits(int a, int b){
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(a,b);
    /*for (int i = 0; i<10; i++){
        double number = distribution(generator);
        cout << number << endl;
        }*/
    return distribution(generator);
}
