#pragma once
#include "Iterator.h"

class List{
public:
    virtual Node* getBuffer() = 0;
    virtual void add(Iterator* it, int v) = 0;
    virtual void remove(Iterator* it) = 0;
    virtual Iterator* indexOf(int v) = 0;
    virtual void empty() = 0;
    virtual bool isEmpty() = 0;
    virtual int getLength() = 0;
    virtual Iterator* begin() = 0;
};
