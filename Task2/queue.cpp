#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue(const Queue& queue){
    buffer = queue.buffer;
    arr = new int[buffer];
    for(int i = 0; i < buffer; i++){
        arr[i] = queue.arr[i];
    }
    iBegin = queue.iBegin;
    iEnd = queue.iEnd;
    length = queue.length;
}

Queue::Queue(int n){
    iBegin = 0;
    iEnd = -1;
    length = 0;
    buffer = n;
    arr = new int[n];
}

void Queue::add(int v){
    if (length == buffer) {
        throw invalid_argument("overflow");
    }
    iEnd = (iEnd+1)%buffer;
    arr[iEnd] = v;
    length++;
}

int Queue::pop(){
    if(length == 0){
        throw invalid_argument("is empty");
    }
    int t = arr[iBegin];
    length--;
    iBegin = (iBegin+1)%buffer;
    return t;
}

int Queue::get() const{
    if(length == 0){
        throw invalid_argument("is empty");
    }
    return arr[iBegin];
}

int Queue::size() const{
    return length;
}

void Queue::empty(){
    iBegin = -1;
    iEnd = 0;
    length = 0;
}

bool Queue::isEmpty(){
    return length == 0;
}
