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

DynamicArray::DynamicArray(DynamicArray d_arr)
{
    arr = new int[d_arr.length()];
    for(int i = 0; i < n; i++){
        arr[i] = d_arr[i];
    }
}



DynamicArray::~DynamicArray()
{
    //dtor
}
