#pragma once
class Queue{
    private:
        int* arr;
        int buffer;
        int length;
        int iEnd;
        int iBegin;
    public:
        Queue(int);
        Queue(const Queue&);
        void add(int);
        int pop();
        int get() const;
        int size() const;
        void empty();
        bool isEmpty();
};
