#include "tree.h"

using namespace std;

Tree::Tree() {

}

Tree::Tree(const Tree& tree) {
    head = copyTree(tree.head);
    length = tree.length;
}

Tree::~Tree() {
    removeLeaf(head);
}


void Tree::add(int x){
    Node* p = new Node(x);
    head = p;
}

void Tree::add(int x, int path[], int size){
    Node* p = head;
    for(int i = 0; i < size - 1; i++){
        if(p == nullptr){
            throw invalid_argument("invalid path");
        }
        if (path[i]) {
            p = p -> right;
        } else if(!path[i]) {
            p = p -> left;
        }

    }
    Node* t = new Node(x);
    if (path[size - 1]) {
        if(p -> right != nullptr){
            p -> right -> value = x;
        } else {
            p -> right = t;
        }
    } else if(!path[size - 1]) {
        if(p -> left != nullptr){
            p -> left -> value = x;
        }else{
            p -> left = t;
        }
    }
}

int Tree::countEven(){
    return countEven(head);
}

bool Tree::isAllPositive(){
    return isAllPositive(head);
}

void Tree::deleteLeaves(){
    return deleteLeaves(head);
}

double Tree::getAverageValue() {
    SumAndCount elem = getSumAndCount(head);
    cout << elem.count << endl;
    return elem.sum /(double) elem.count;
}

vector<int> Tree::findElem(int x){
    vector<int> v;
    if(findElemRec(x, head, v)){
        return v;
    }
    throw invalid_argument("Error, find");
}

