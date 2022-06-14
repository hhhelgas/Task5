#include "DynamicArray.h"

DynamicArray::DynamicArray()
{
    length = 0;
    buffer = 0;
    arr = new int[10];
}

DynamicArray::DynamicArray(int n)
{
    length = n;
    buffer = 0;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }
}

DynamicArray::DynamicArray(int n, int v)
{
    buffer = 0;
    length = n;
    arr = new int[n];
    for(int i = 0; i < n; i++){
        arr[i] = v;
    }
}

DynamicArray::DynamicArray(const DynamicArray& d_arr)
{
    buffer = d_arr.capacity();
    length = d_arr.getLength();
    arr = new int[d_arr.getLength()];
    for(int i = 0; i < d_arr.getLength(); i++){
        arr[i] = d_arr[i];
    }
}

DynamicArray::DynamicArray(DynamicArray&& d_arr){
    arr = d_arr.arr;
    length = d_arr.length;
    buffer = d_arr.buffer;
    d_arr.buffer = 0;
    d_arr.arr = nullptr;
    d_arr.length = 0;
}

DynamicArray::~DynamicArray()
{
    delete[] arr;
}

int DynamicArray::getLength() const{
    return length;
}

void DynamicArray::resize(int n)/*меняет длину без резерва(buffer)*/{
    if (n <= length + buffer) {
        buffer -= n - length;
        length = n;
        return;
    }else if(n < length){
        buffer += length - n;
        length = n;
        return;
    }
    int* new_arr = new int[n];
    for (int i = 0; i < getLength(); i++) {
        new_arr[i] = arr[i];
    }
    for (int i = getLength(); i < n; i++) {
        new_arr[i] = 0;
    }
    delete[] arr;
    arr = new_arr;
    length = n;
}

void DynamicArray::reserve(int n)/*добавляет к буферу n*/{
    int size = length;
    resize(length + buffer + n);
    length = size;
    buffer += n;
}

int DynamicArray::capacity() const{
    return buffer;
}

void DynamicArray::pushBack(int x){
    resize(length + 1);
    arr[length - 1] = x;
}

int DynamicArray::popBack(){
    int value = arr[length - 1];
    resize(length - 1);
    return value;
}
