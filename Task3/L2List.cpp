#include "L2List.h"
#include "iostream"

L2List::L2List(){
    buffer = new Node;
    buffer -> next = NULL;
    buffer -> prev = NULL;
    length = 0;
}

void L2List::add(Iterator it, int v) override {
    it.get() = v;
}

void L2List::remove(Iterator it) override {
    Node* p = it.get();
    p -> prev -> next = p -> next;
    delete p;
}



