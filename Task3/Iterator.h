#pragma once

struct Node{
    int value;
    Node* next;
    Node* prev;
};

class Iterator{
protected:
    Node* p;
    Node* buf;
    int index;
    int length;
public:
    virtual void start(){}
    virtual Node* get(){}
    virtual void next(){}
    virtual bool finish(){}
};
