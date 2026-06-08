#pragma once
#include <iostream>

template<typename type, int size>
class MyArray{
private:
    type arr[size];

public:
    int getSize(){
        return size;
    }

    type& at(int index){
        if (index<size){
            return arr[index];
        } else {
            std::cout << "Not an index in this array, here is the first index" <<std::endl;
            return arr[0];
        }
    }

    void fill(type a){
        for (int i=0;i<size;i++){
            arr[i]=a;
        }
    }
};