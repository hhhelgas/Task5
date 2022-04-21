#pragma once

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
    HashTable& operator=(const HashTable& hashTable)
    {
        if(this != &hashTable){

        }
        return *this;
    }
    void add(int, int);
    void remove(int);
    Node* indexOf(int);
    void empty();
    bool isEmpty();
};
