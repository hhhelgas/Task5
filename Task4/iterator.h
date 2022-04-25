#pragma once
#include <iostream>
#include "hashtable.h"

class Iterator{
private:
    int index;
    int length;
    int buffer;
    int status;
    bool isStatus = 0;
    Node* arr;
    Node* elem;
public:
    Iterator(HashTable&);
    void start();
    void next();
    bool finish();
    int getValue();
};
