#include "std_lib_facilities.h"
#include "tests.h"
#include "utilities.h"
#include "Mastermind.h"
#include "masterVisual.h"


//1a) Vo=5 fortsatt

//2e) Because #pragma once is not included at the top of the utilities header,
//Student gets defined twice, which is not allowed in C++

//4a) Jeg forstår ike hvorfor vi bruker constexpr


int val(int v){
    v=1;
} //Can't have a constexpr as an argument)


int main() {

    constexpr int v=5;
    val(v);

    Mastermind();
    return 0;
}

//------------------------------------------------------------------------------
