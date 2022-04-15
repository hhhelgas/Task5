#include "L2List.h"
#include "iostream"

L2List::L2List(){
    buffer = new Node;
    buffer -> next = nullptr;
    buffer -> prev = nullptr;
    buffer -> value = -2;
    length = 0;
}

L2List::L2List(const L2List& _list){
    buffer = new Node;
    Node* p = _list.buffer -> next;
    Node* t;
    Node* tl = buffer;
    while(p -> next != _list.buffer){
        t = new Node;
        tl -> next = t;
        t -> prev = tl;
        t -> value = p -> value;
        tl = tl -> next;
    }
    buffer -> prev = tl;
    tl -> next = buffer;
    length = _list.length;
}





