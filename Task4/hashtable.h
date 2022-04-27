#pragma once
#include <iostream>
struct Node{
    int key;
    int value;
    Node* next;
};

class HashTable{
private:
    Node* arr;
    int buffer;
    int size;
    int hashFunc(int key) {
        return key % buffer;
    }
public:
    HashTable();
    HashTable(const HashTable&);
    HashTable(HashTable&&);
    ~HashTable();
    HashTable& operator=(HashTable& hashTable)
    {
        if(this != &hashTable){
            HashTable local(hashTable);
            std::swap(arr, local.arr);
            std::swap(buffer, local.buffer);
            std::swap(size, local.size);
        }
        return *this;
    }
    HashTable& operator=(HashTable&& hashTable)
    {
        if (this != &hashTable) {
            std::swap(arr, hashTable.arr);
            std::swap(buffer, hashTable.buffer);
            std::swap(size, hashTable.size);
        }
        return *this;
    }
    void add(int, int);
    void remove(int);
    Node* indexOf(int);
    void empty();
    bool isEmpty();
    Node* getArr();
    int getLength();
    int getBuffer();
};
