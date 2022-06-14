#include <iostream>
#include "DynamicArray.h"
using namespace std;

int f(DynamicArray& arr,int n){
    DynamicArray arr1;
    arr1 = arr;
    return arr[n];
}

int main()
{
    DynamicArray d_arr(5,1);
    cout << "Length: " << d_arr.getLength() << endl;
    cout << d_arr << endl;
    d_arr[1] = 2;
    f(d_arr, 1);
    f(d_arr, 1);
    cout << "elem[1]: " << d_arr[1] << endl;
    cout << d_arr << endl;
    cout << "resize" << endl;
    d_arr.resize(10);
    cout << d_arr << endl;

    DynamicArray d_arr2(2, 10);

    DynamicArray d_arr_sum(d_arr + d_arr2);
    cout << d_arr_sum << endl;

    DynamicArray d_arr3(6,2);

    cout << d_arr << " > " << d_arr3 << ": " << (d_arr > d_arr3) << endl;

    DynamicArray d_arr4 = DynamicArray(d_arr3);

    cout << d_arr << " == " << d_arr4 << ": " << (d_arr == d_arr4) << endl;

    d_arr.reserve(3);
    cout << "buffer: " << d_arr.capacity();
    cout << " length: "<< d_arr.getLength() << endl;

    d_arr.resize(8);
    cout << "buffer: " << d_arr.capacity();
    cout << " length: " << d_arr.getLength() << endl;

    cout << d_arr << endl;
    d_arr.pushBack(9);
    cout << "buffer: " << d_arr.capacity();
    cout << " length: " << d_arr.getLength() << endl;

    cout << d_arr << endl;
    cout << d_arr.popBack() << endl;
    cout << d_arr << endl;
    cout << d_arr.capacity() << endl;
    cout << d_arr.getLength() << endl;

    return 0;
}
