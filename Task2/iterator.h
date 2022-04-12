#pragma once
#include "queue.h"
class Iterator{
    private:
        Queue q;
        int index;
        int length;
    public:
        Iterator(Queue&);
        void start();
        void next();
        bool finish();
        int getValue();
};
