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
    virtual void start() = 0;
    virtual Node* get() = 0;
    virtual void next() = 0;
    virtual bool finish() = 0;
};
