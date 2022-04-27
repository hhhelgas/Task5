#pragma once
#include <iostream>
#include "hashtable.h"

class Iterator{
private:
    int index;
    int length;
    int buffer;
    Node* elem;
    Node* arr;
public:
    Iterator(HashTable&);
    void start();
    void next();
    bool finish();
    int getValue();
};
