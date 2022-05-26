#include "iterator.h"
#include "hashtable.h"
#include <iostream>

Iterator::Iterator(HashTable& hashTable){
    arr = hashTable.getArr();
    //order = hashTable.getOrder();
    buffer = hashTable.getBuffer();
    length = hashTable.getLength();
    //length = hashTable.getOrder().size();
}

/*void Iterator::start(){
    index = 1;
}

void Iterator::next() {
    std::cout << "\nind " << index - 1 << " " << length << "\n";
    if (index < length) {
        index++;
    }
}

bool Iterator::finish() {
    return index >= length - 1;
}

int Iterator::getValue() {
    std::cout << "\n" << order.size() << " " << index - 1 << "\n";
    return order.at(index-1);
}*/

void Iterator::start(){
    index = 0;
    if(length != 0){
        while(arr[index].next == nullptr){
            index++;
        }
        elem = arr[index].next;
    }
}

void Iterator::next(){
    if(!finish()) {
        if(elem -> next == nullptr) {
            index++;
            while(index < buffer && arr[index].next == nullptr){
                index++;
            }
            elem = arr[index].next;
        } else {
            elem = elem -> next;
        }
    }
}

bool Iterator::finish(){
    return index >= length;
}

int Iterator::getValue(){
    return elem -> value;
}
