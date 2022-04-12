#pragma once
#include "Iterator.h"

class List{
public:
    virtual void add(Iterator it, int v){}
    virtual void remove(Iterator it){}
    virtual Iterator indexOf(int v){}
    virtual void empty(){}
    virtual bool isEmpty(){}
    virtual int getLength(){}
    virtual Iterator begin(){}
};
