#include "iterator.h"
#include "queue.h"

Iterator::Iterator(Queue& _queue):q(_queue){
    index = 0;
    length = q.size();
}

void Iterator::start(){
    index = 0;
}

void Iterator::next(){
    if(index < length){
        index++;
        q.pop();
    }
}

bool Iterator::finish(){
    return index == length;
}

int Iterator::getValue(){
    return q.get();
}
