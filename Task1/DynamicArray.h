#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>

class DynamicArray
{
    private:
        int* arr;
        int length;
        int buffer;//����� �������, ������� �� ����� ������������,�� ����� ��� ���������� �������
    public:
        DynamicArray();
        DynamicArray(int);//����������� �� �����, ��� �������� 0
        DynamicArray(int, int);//����������� �� ����� � ��� �������� ����� �����
        DynamicArray(const DynamicArray&);//����������� �����������
        DynamicArray(DynamicArray&&);//����������� �����������
        ~DynamicArray();//����������
        int getLength() const;
        void reserve(int);//������ �����
        int capacity() const;//������ ������
        int popBack();//������� ��������� �������
        void pushBack(int);//��������� ��������� �������
        int& operator[](int i) const /*��������[] ��������� � ��������� ��������*/{
            if(i >= length){
                throw std::invalid_argument("error index");
            }
            return arr[i];
        }
        void resize(int);//������ ����� �������
        DynamicArray& operator=(DynamicArray&& d_arr)/*�������� �����������*/{
            if (this != &d_arr)
            {
                delete[] arr;

                arr = d_arr.arr;
                length = d_arr.length;

                d_arr.arr = nullptr;
                d_arr.length = 0;
            }
            return *this;
        }
        DynamicArray& operator=(DynamicArray& d_arr)/*�������� ������������*/{
            if(this != &d_arr){
                DynamicArray local = DynamicArray(d_arr);
                std::swap(arr, local.arr);
                std::swap(length, local.length);
            }
            return *this;
        }
        friend bool operator== (const DynamicArray &arr1, const DynamicArray &arr2){
            if(arr1.getLength() == arr2.getLength()){
                for(int i = 0; i < arr1.getLength(); i++){
                    if(arr1[i] != arr2[i]){
                        return false;
                    }
                }
                return true;
            }
            return false;
        }
        friend bool operator!= (const DynamicArray &arr1, const DynamicArray &arr2){
            return !(arr1 == arr2);
        }
        friend bool operator< (const DynamicArray &arr1, const DynamicArray &arr2){
            if(arr1.getLength() < arr2.getLength()){
                return true;
            }else if(arr1.getLength() > arr2.getLength()){
                return false;
            }else{
                for(int i = 0; i < arr1.getLength(); i++){
                    if(arr1[i] > arr2[i]){
                        return false;
                    }else if(arr1[i] < arr2[i]){
                        return true;
                    }
                }
            }
            return false;
        }
        friend bool operator<= (const DynamicArray &arr1, const DynamicArray &arr2){
            return (arr1 < arr2 || arr1 == arr2);
        }
        friend bool operator> (const DynamicArray &arr1, const DynamicArray &arr2){
            return !(arr1 <= arr2);
        }
        friend bool operator>= (const DynamicArray &arr1, const DynamicArray &arr2){
            return (arr1 > arr2 || arr1 == arr2);
        }
        friend DynamicArray operator+ (const DynamicArray& arr1, const DynamicArray& arr2){
            DynamicArray result(arr1.getLength() + arr2.getLength());
            int j = 0;
            for(int i = 0; i < arr1.getLength(); i++){
                result[j] = arr1[j];
                j++;
            }
            for(int i = 0; i < arr2.getLength(); i++){
                result[j] = arr2[i];
                j++;
            }
            return result;
        }
        friend std::ostream& operator<< (std::ostream& out, const DynamicArray& d_arr){
            out << "{";
            for(int i = 0; i < d_arr.getLength()-1; i++){
                out << d_arr[i] << " ";
            }
            out << d_arr[d_arr.getLength()-1] << "}";
            return out;
        }
        friend std::istream& operator>> (std::istream& in, DynamicArray& d_arr){
            for(int i = 0; i < d_arr.getLength(); i++){
                in >> d_arr[i];
            }
            return in;
        }
};
#endif // DYNAMICARRAY_H
