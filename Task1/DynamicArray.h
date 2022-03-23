#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


class DynamicArray
{
    public:
        DynamicArray();
        DynamicArray(int);
        DynamicArray(int, int);
        DynamicArray(DynamicArray);
        DynamicArray(DynamicArray&&);
        virtual ~DynamicArray();
        int length();
        friend int operator[](int);
        void resize(int);
        friend DynamicArray operator=(DynamicArray);
        friend bool operator== (const DynamicArray &arr1, const DynamicArray &arr2);
        friend bool operator!= (const DynamicArray &arr1, const DynamicArray &arr2);
        friend bool operator< (const DynamicArray &arr1, const DynamicArray &arr2);
        friend bool operator<= (const DynamicArray &arr1, const DynamicArray &arr2);
        friend bool operator> (const DynamicArray &arr1, const DynamicArray &arr2);
        friend bool operator>= (const DynamicArray &arr1, const DynamicArray &arr2);
        friend DynamicArray operator+ (const DynamicArray &arr1, const DynamicArray &arr2);
        friend ostream& operator<< (ostream &out, const DynamicArray &arr);
        friend istream& operator>> (istream &in, DynamicArray &arr);
    private:
        int* arr;
};

int& operator[](int i){
    return arr[i];
}

bool operator== (const DynamicArray &arr1, const DynamicArray &arr2){
    if(arr1.length() == arr2.length()){
        for(int i = 0; i < arr1.length(); i++){
            if(arr1[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
    return false;
}

bool operator!= (const DynamicArray &arr1, const DynamicArray &arr2){
    return !(arr1 == arr2);
}

bool operator< (const DynamicArray &arr1, const DynamicArray &arr2){
    if(arr1.length() < arr2.length){
        return true;
    }else if(arr1.length() > arr2.length()){
        return false;
    }else{
        for(int i = 0; i < arr1.length(); i++){
            if(arr1[i] > arr2[i]){
                return false;
            }else if(arr1[i] < arr2[i]){
                return true;
            }
        }
    }
    return false;
}

DynamicArray operator+ (const DynamicArray &arr1, const DynamicArray &arr2){
    DynamicArray arr = new DynamicArray(arr1.length() + arr2.length());
    for(int i = 0; i < arr1.length(); i++){
        arr[i] = arr1[i];
    }
    for(int i = 0; i < arr2.length(); i++){
        arr[i] = arr2[i];
    }
}

bool operator<= (const DynamicArray &arr1, const DynamicArray &arr2){
    return (arr1 < arr2 || arr1 == arr2);
}

bool operator> (const DynamicArray &arr1, const DynamicArray &arr2){
    return !(arr1 <= arr2);
}

bool operator>= (const DynamicArray &arr1, const DynamicArray &arr2){
    return (arr1 > arr2 || arr1 == arr2);
}


ostream& operator<< (ostream &out, const DynamicArray &arr){
    for(int i = 0; i < arr.length(); i++){
        out << arr[i] << " ";
    }
    return out;
}

istream& operator>> (istream &in, DynamicArray &arr){
    for(int i = 0; i < arr.length(); i++){
        in >> arr[i];
    }
    return in;
}
#endif // DYNAMICARRAY_H
