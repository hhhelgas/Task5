#pragma once
#include <iostream>
#include <vector>

struct Node{
    int value;
    Node* left;
    Node* right;
    friend std::ostream& operator<< (std::ostream& out, Node* node){
        if(node -> left != nullptr){
            out << node -> left;
        }
        if(node -> right != nullptr) {
            out << node -> right;
        }
        out << node -> value << " ";
        return out;
    }
    Node(int value, Node* left = nullptr, Node* right = nullptr){
        this -> value = value;
        this -> left = left;
        this -> right = right;
    }
};

struct SumAndCount{
    int count;
    int sum;
    SumAndCount(int sum, int count = 1){
        this -> sum = sum;
        this -> count = count;
    }
};

class Tree{
private:
    Node* head;
    int length;

    Node* copyTree(Node* rt){
        if(!rt){
            return nullptr;
        }
        Node* leaf = new Node(rt -> value, copyTree(rt -> left), copyTree(rt -> right));
        return leaf;
    }

    void removeLeaf(Node* p){
        if(p == nullptr){
            return;
        }
        removeLeaf(p -> left);
        removeLeaf(p -> right);
        delete p;
    }

    void print(Node* node, int tab){
        std::cout << node -> value << "\n";
        if(node -> left != nullptr){
            tab += 4;
            for(int i = 0; i < tab; i++){
                std::cout << " ";
            }
            print(node -> left, tab);
            std::cout << "\n";
            tab -= 4;
        }
        if(node -> right != nullptr) {
            tab += 4;
            for(int i = 0; i < tab; i++){
                std::cout << " ";
            }
            print(node -> right, tab);
            std::cout << "\n";
            tab -= 4;
        }
    }

    friend std::ostream& operator<< (std::ostream& os, const Tree& tree){
        os << tree.head;
        return os;
    }

    int countEven(Node* p) {
        if(!p){
            return 0;
        }
        return countEven(p -> right) + countEven(p -> left) + (p -> value + 1) % 2;
    }

    bool isAllPositive(Node* p){
        if(!p){
            return true;
        }
        return isAllPositive(p -> left) && isAllPositive(p -> right) && (p -> value > 0);
    }

    void deleteLeaves(Node* p) {
        Node* t;
        if(p){
            if (p -> left){
                if (!p -> left -> left && !p -> left -> right) {
                    t = p -> left;
                    p -> left = nullptr;
                    delete t;
                }
            }
            if (p -> right){
                if (!p -> right -> left && !p -> right -> right) {
                    t = p -> right;
                    p -> right = nullptr;
                    delete t;
                }
            }
            deleteLeaves(p -> left);
            deleteLeaves(p -> right);
        }
    }

    SumAndCount getSumAndCount(Node* root){
        if (!root) {
            return SumAndCount(0,0);
        }
        SumAndCount left = getSumAndCount(root -> left);
        SumAndCount right = getSumAndCount(root -> right);
        return SumAndCount(left.sum + right.sum + root -> value, right.count + left.count + 1);
    }

    int findElemRec(int x, Node* p, std::vector<int>& v) {
        if (!p) {
            return 0;
        }
        if(p -> value == x){
            return 1;
        }
        if (findElemRec(x, p -> left, v)) {
            v.insert(v.begin(), 0);
            return 1;
        }
        if(findElemRec(x, p -> right, v)){
            v.insert(v.begin(), 1);
            return 1;
        }

        return 0;
    }

    bool isBinarySearch (Node* p, int mode, int value) {
        if(!p){
            return 1;
        }
        if(mode == 1){
            return isBinarySearch(p -> left, 1, p -> value) && isBinarySearch(p -> right, 2, p -> value) && p -> value < value;
        }else if(mode == 2){
            return isBinarySearch(p -> left, 1, p -> value) && isBinarySearch(p -> right, 2, p -> value) && p -> value > value;
        }
        return isBinarySearch(p -> left, 1, p -> value) && isBinarySearch(p -> right, 2, p -> value);
    }

public:
    Tree();
    Tree(const Tree&);
    Tree(Tree&&);
    ~Tree();
    void add(int, int*, int);
    int countEven();
    bool isAllPositive();
    void deleteLeaves();
    double getAverageValue();
    bool isBinarySearch();
    void print();
    std::vector<int> findElem(int x);
    Tree& operator=(Tree& tree)
    {
        if (this != &tree) {
            Tree local(tree);
            std::swap(head, local.head);
            std::swap(length, local.length);
        }
        return *this;
    }
    Tree& operator=(Tree&& tree)
    {
        if (this != &tree) {
            std::swap(head, tree.head);
            std::swap(length, tree.length);
        }
        return *this;
    }
};
