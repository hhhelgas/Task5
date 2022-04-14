#include "L2List.h"
#include "iostream"

L2List::L2List(){
    buffer = new Node;
    buffer -> next = buffer;
    buffer -> prev = buffer;
    buffer -> value = -2;
    length = 0;

    std::cout << "constructor list\n" << buffer -> value;
}

L2List::L2List(const L2List& _list){
    /*buffer = new Node;
    buffer -> next = buffer;
    buffer -> prev = buffer;
    L2Iterator it(*this);
    it.start();
    Node* p = _list.buffer -> next;
    while(p -> next != _list.buffer){
        add(it, p -> value);
        it.next();
        p = p -> next;
    }*/
    std::cout << "copy const begin\n";
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
    std::cout << "copy const end\n";
}





