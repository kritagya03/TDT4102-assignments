#include <iostream>
#include "Matrix.h"

void fillInFibonacciNumbers(int* result, int length){
    //result=new int[length];
    int a=0;
    int b=1;
    for (int i=0;i<length;i++){
        result[i]=a;

        int save=a;
        a=b;
        b=save+b;
    }
}

void printArray(int* arr, int length){
    for (int i=0;i<length;i++){
        std::cout << arr[i] <<std::endl;
    }
}

void createFibonacci(){
    int length;
    std::cout << "How long do you wish your fibonachi sequence to be? ";
    std::cin >> length;

    int* fibon=new int[length]; //R T D

    fillInFibonacciNumbers(fibon,5);
    printArray(fibon,5);

    delete[] fibon;
}

int& var(){
    int d=2;
    return d;
}

int main() {
    Matrix d(4,3);

    Matrix b(4,3);
    Matrix c(5);

    b.set(1,1,2);
    d.set(1,1,3);
    b+=d;

    Matrix k = b+c;

    std::cout << b;
    return 0;
}

//------------------------------------------------------------------------------
