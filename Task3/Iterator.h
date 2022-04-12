#pragma once

struct Node{
    int value;
    Node* next;
    Node* prev;
};

class Iterator{
public:
    virtual void start(){}
    virtual Node& get(){}
    virtual void next(){}
    virtual bool finish(){}
};
