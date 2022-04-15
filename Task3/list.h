#pragma once
#include "Iterator.h"

class List{
protected:
    Node* buffer;
    int length;
public:
    virtual Node* getBuffer(){}
    virtual void add(Iterator it, int v){}
    virtual void remove(Iterator it){}
    virtual Iterator indexOf(int v){}
    virtual void empty(){}
    virtual bool isEmpty(){}
    virtual int getLength(){}
    virtual Iterator& begin(){}
};
