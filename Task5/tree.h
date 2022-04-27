#pragma once
#include <iostream>

struct Node{
    int value;
    Node* left;
    Node* right;
};

class Tree{
private:
    Node* head;
    int length;
    void addLeaf(Node* p){
        Node* nide
        if(p != nullptr){

        }
    }
    void removeLeaf(Node* p){
        if(p -> left != nullptr){
            removeLeaf(p -> left);
        }
        if(p -> right != nullptr){
            removeLeaf(p -> right);
        }
        if(p -> left == nullptr && p -> right == nullptr){
            delete p;
        }
    }
public:
    Tree();
    ~Tree();
    add(int, bool*);
};
