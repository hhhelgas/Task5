#include <iostream>
#include "tree.h"
#include <cstring>

using namespace std;

Tree::Tree(){
    size = 0;
    head = nullptr;
}

Tree::Tree(const Tree& tree) {
    std::cout << "copy\n";
    head = copyTree(tree.head);
    size = tree.size;
}

Tree::Tree(Tree&& tree){
    head = tree.head;
    size = tree.size;
    tree.head = nullptr;
    tree.size = 0;
}

Tree::~Tree() {
    removeLeaf(head);
}

void Tree::add(char* word){
    size++;
    if(!head){
        head = new Node(word);

        return;
    }
    Node* p = head;
    while(p){
        int compare = strcmp(word, p -> key);
        if (compare == 0) {
            (p -> value)++;
            break;
        } else if (compare > 0) {
            if(!p -> right){
                //std::cout << "add right " << word << " " << p -> key << "\n";
                p -> right = new Node(word);
                break;
            }
            p = p -> right;
        } else {
            if(!p -> left){
                //std::cout << "add left " << word << " " << p -> key << "\n";
                p -> left = new Node(word);
                break;
            }
            p = p -> left;
        }
    }
}

void Tree::remove(char* word){
    deleteElem(head, word);
    size--;
}

int Tree::countWords(){
    return size;
}

int Tree::findWord(char* word){
    return findWord(head, word);
}
/*void Tree::remove(char* word){
    Node* p = head;
    Node* prev = head;
    bool found = true;
    while(p) {
        int compare = strcmp(word, p -> key);
        if (compare == 0 && p -> value > 1) {
            (p -> value)--;
            break;
        } else if (compare == 0) {
            if (!p -> left) {
                prev = prev -> right;
                delete p;
            }else{
                if

            }
        } else  if (compare > 0){
            if (!p -> right) {
                found = false;
                break;
            }
            prev = p;
            p = p -> right;
        } else if(compare < 0) {
            if (!p -> left) {
                found = false;
                break;
            }
            prev = p;
            p = p -> left;
        }
    }
    if(found){
        size--;
    }
}*/




