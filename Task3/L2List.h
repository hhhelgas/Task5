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
        List list;
        Node* p;
        int index;
    public:
        L2Iterator(L2List& _list):list(_list){}
        void start() override{
            p = list.buffer;
            index = 0;
        }
        void next() override{
            p = p -> next;
            i++;
        }
        Node& get() override{
            return p;
        }
        bool finish() override{
            return index >= length;
        }
    };
    L2List();
    //L2List(const L2List&);
    void add(Iterator it, int v) override;
    void remove(Iterator it) override;
};
