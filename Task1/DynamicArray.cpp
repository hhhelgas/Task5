#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    length = 0;
    arr = new int[10];
}

DynamicArray::DynamicArray(int n)
{
    length = n;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }
}

DynamicArray::DynamicArray(int n, int v)
{
    length = n;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = v;
    }
}

DynamicArray::DynamicArray(const DynamicArray& d_arr)
{
    length = d_arr.getLength();
    arr = new int[d_arr.getLength()];
    for(int i = 0; i < d_arr.getLength(); i++){
        arr[i] = d_arr[i];
    }
}

DynamicArray::DynamicArray(DynamicArray&& d_arr):arr(nullptr),length(0){
    arr = d_arr.arr;
    length = d_arr.length;
    d_arr.arr = nullptr;
    length = 0;
}

DynamicArray::~DynamicArray()
{
    delete[] arr;
}

int DynamicArray::getLength() const{
    return length;
}

void DynamicArray::resize(int n){
    int* new_arr = new int[n];
    for(int i = 0; i < getLength(); i++){
        if(i < n){

            new_arr[i] = arr[i];
        }
    }
    delete[] arr;
    arr = new_arr;
    length = n;
}
