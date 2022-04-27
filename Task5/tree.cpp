#include "tree.h"

using namespace std;

Tree::Tree() {

}

Tree::Tree(const Tree& tree) {

}

Tree::~Tree() {
    removeLeaf(head);
}

Tree::add(int x, bool* path){
    Node* p = head;
    for(int i = 0; i < sizeof(path)/sizeof(path[0]); i++){
        if (path[i]) {
            p = p -> right;
        } else if(!path[i]) {
            p = p -> left;
        }
        if(p == nullptr){
            throw invalid_argument("invalid path");
        }
    }
}


