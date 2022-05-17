#include <iostream>
#include "DynamicArray.h"
using namespace std;

int main()
{
    DynamicArray d_arr(5,1);
    cout << "Length: " << d_arr.getLength() << endl;
    cout << d_arr << endl;
    d_arr[1] = 2;
    cout << "elem[1]: " << d_arr[1] << endl;
    cout << d_arr << endl;
    cout << "resize" << endl;
    d_arr.resize(6);
    cout << d_arr << endl;

    DynamicArray d_arr2(2, 10);

    DynamicArray d_arr_sum(d_arr + d_arr2);
    cout << d_arr_sum << endl;

    DynamicArray d_arr3(6,2);

    cout << d_arr << " > " << d_arr3 << ": " << (d_arr > d_arr3) << endl;

    DynamicArray d_arr4 = DynamicArray(d_arr3);

    //d_arr4 = d_arr;

    cout << d_arr << " == " << d_arr4 << ": " << (d_arr == d_arr4) << endl;



    return 0;
}
