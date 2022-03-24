#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    arr = new int[10];
}

DynamicArray::DynamicArray(int n)
{
    arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }
}

DynamicArray::DynamicArray(int n, int v)
{
    arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = v;
    }
}

DynamicArray::DynamicArray(const DynamicArray& d_arr)
{
    arr = new int[d_arr.getLength()];
    for(int i = 0; i < d_arr.getLength(); i++){
        arr[i] = d_arr[i];
    }
}

DynamicArray::DynamicArray(DynamicArray&& d_arr):arr(nullptr){
    arr = d_arr.arr;
    length = d_arr.length;
}

DynamicArray::~DynamicArray()
{
    delete[] arr;
    //dtor
}

int DynamicArray::getLength() const{
    return length;
}
