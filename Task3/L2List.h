#pragma once
#include "List.h"
#include "Iterator.h"
#include <iostream>

class L2List: public List{
private:
    Node* buffer;
    int length;
public:
    class L2Iterator: public Iterator{
    private:
        Node* p;
        Node* buf;
        int index;
        int length;
    public:
        L2Iterator(L2List& _list){
            buf = _list.getBuffer();
            length = _list.getLength();
        }
        void start() override{
            p = buf;
            index = -1;
        }
        void next() override{
            p = p -> next;
            index++;
        }
        Node* get() override{
            return p;
        }
        bool finish() override{
            return index >= length - 1;
        }
    };
    L2List();
    L2List(const L2List&);
    L2List(L2List&&);
    ~L2List();
    void add(Iterator* it, int v) override{
        Node* p = new Node;
        if(length == 0){
            p -> next = buffer;
            p -> prev = buffer;
            p -> value = v;
            buffer -> next = p;
            buffer -> prev = p;
        }else{
            Node* t = it -> get();
            t -> next -> prev = p;
            p->next = t->next;
            p->prev = t;
            p->value = v;
            t->next = p;
        }
        length++;
    }
    Node* getBuffer() override{
        return buffer;
    }

    void remove(Iterator* it) override{
        Node* p = it->get();
        p -> next -> prev = p -> prev;
        p -> prev -> next = p -> next;
        delete p;
        length--;
    }

    Iterator* indexOf(int v) override{
        Node* p = buffer -> next;
        int i = 0;
        while(p != buffer){
            i++;
            if(p -> value == v){
                break;
            }
            p = p -> next;
        }
        Iterator* it = new L2Iterator(*this);
        it->start();
        for(int j = 0; j < i; j++){
            it->next();
        }
        return it;
    }

    void empty() override {
        Node* p = buffer;
        Node* t = NULL;
        while(p -> next != buffer){
            p = p -> next;
            delete t;
            t = p;
        }
        delete t;
        length = 0;
    }
    bool isEmpty() override {return length == 0;}
    int getLength() override {return length;}
    Iterator* begin() override{
        Iterator* it = new L2Iterator(*this);
        it->start();
        it->next();
        return it;
    }
    L2List operator=(L2List& _list){
        buffer = _list.buffer;
        length = _list.length;
        return *this;
    }
};
