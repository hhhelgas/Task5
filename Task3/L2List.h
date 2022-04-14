#pragma once
#include "List.h"
#include "Iterator.h"
#include <iostream>

class L2List: public List{
public:
    L2List();
    L2List(const L2List&);
    void add(Iterator it, int v) override {
        Node* p = new Node;
        Node* t = it.get();
        t -> next -> prev = p;
        p -> next = t -> next;
        p -> prev = t;
        p -> value = v;
        t -> next = p;
        length++;
    }
    Node* getBuffer() override{
        return buffer;
    }

    void remove(Iterator it) override {
        Node* p = it.get();
        p -> prev -> next = p -> next;
        p -> next -> prev = p -> prev;
        delete p;
        length--;
    }
    Iterator indexOf(int v) override{
        Node* p = buffer -> next;
        int i = -1;
        while(p != buffer -> prev){
            i++;
            if(p -> value == v){
                break;
            }
            p = p -> next;
        }
        L2Iterator it(*this);
        it.start();
        for(int j = 0; j <= i; j++){
            it.next();
        }
        return it;
    }
    void empty() override{
        Node* p = buffer;
        Node* t = NULL;
        while(p -> next != nullptr){
            p = p -> next;
            delete t;
            t = p;
        }
        delete t;
        length = 0;
    }
    bool isEmpty() override {return length == 0;}
    int getLength() override {return length;}
    Iterator& begin() override{
        std::cout << "begin\n";
        L2Iterator it(*this);
        it.start();
        it.next();
        return it;
    }
    L2List operator=(L2List& _list){
        buffer = _list.buffer;
        length = _list.length;
        return *this;
    }
    class L2Iterator: public Iterator{
    private:
        List list;
        Node* p;
        int index;
    public:
        L2Iterator(List& _list):list(_list){std::cout << "constructor iterator\n";}
        void start() override{
            p = list.getBuffer();
            index = -1;
        }
        void next() override{
            p = p -> next;
            std::cout << index << " next\n";
            index++;
        }
        Node* get() override{
            return p;
        }
        bool finish() override{
            return index >= list.getLength();
        }
    };
};
