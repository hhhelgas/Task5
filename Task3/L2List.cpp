#include "L2List.h"
#include "iostream"

L2List::L2List(){
    buffer = new Node;
    buffer -> next = buffer;
    buffer -> prev = buffer;
    buffer -> value = -2;
    length = 0;
}

L2List::L2List(const L2List& _list){
    buffer = new Node;
    Node* p = _list.buffer -> next;
    Node* t;
    Node* tl = buffer;
    while(p != _list.buffer){
        t = new Node;
        tl -> next = t;
        t -> prev = tl;
        t -> value = p -> value;
        tl = tl -> next;
        //std::cout << "";
        p = p -> next;
    }
    buffer -> prev = tl;
    tl -> next = buffer;
    length = _list.length;
}

L2List::L2List(L2List&& _list):buffer(nullptr),length(0){
    buffer = _list.buffer;
    length = _list.length;
    _list.buffer = nullptr;
    _list.length = 0;
}

L2List::~L2List(){
    if(length != 0){
        empty();
    }
    delete buffer;
}






