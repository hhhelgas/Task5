#pragma once
#include <iostream>
#include <cstring>

struct Node{
    char* key;
    int value;
    Node* left;
    Node* right;
    friend std::ostream& operator<< (std::ostream& out, Node* node){
        if(node -> left){
            out << node -> left;
        }
        out << node -> key << ":" << node -> value << " ";
        if(node -> right) {
            out << node -> right;
        }
        return out;
    }
    Node (char* key, Node* left = nullptr, Node* right = nullptr, int value = 1) {
        this -> key = key;
        this -> value = value;
        this -> left = left;
        this -> right = right;
    }
};

class Tree {
private:
    Node* head;
    int size;
    bool deleteElem(Node*& root, char* word) {
        if (!root) {
            return false;
        }
        int x = strcmp(word, root -> key);
        if (x < 0) {
            return deleteElem(root -> left, word);
        }
        if (x > 0) {
            return deleteElem(root -> right, word);
        }
        if(x == 0){
            if(root->value > 1){
                (root -> value)--;
            }else{
                Node* nodeToDel = root;

                if (!root -> left) {
                    root = root -> right;
                } else if (!root -> right) {
                    root = root -> left;
                } else {
                    del2(root -> left, nodeToDel);
                }
                delete nodeToDel;
            }
            return true;
        }
    }
    void del2(Node*& leftSubTree, Node*& root)
    {
        if (leftSubTree -> right) { // пока есть потомок справа спускаемся
            del2(leftSubTree -> right, root);
        } else { // это наибольший элемент левого поддерева
            root -> key = leftSubTree -> key;
            root -> value = leftSubTree -> value;
            root = leftSubTree;
            leftSubTree = leftSubTree -> left;
        }
    }

    void removeLeaf(Node* p){
        if(p == nullptr){
            return;
        }
        removeLeaf(p -> left);
        removeLeaf(p -> right);
        delete p;
    }

    Node* copyTree(Node* rt){
        if(!rt){
            return nullptr;
        }
        Node* leaf = new Node(rt -> key, copyTree(rt -> left), copyTree(rt -> right), rt -> value);
        return leaf;
    }

    int findWord(Node*& root, char* word){
        if(!root){
            return 0;
        }
        int x = strcmp(word, root -> key);
        if(x > 0){
            return findWord(root -> right, word);
        }else if(x < 0){
            return findWord(root -> left,word);
        }
        return root -> value;
    }
public:
    Tree();
    Tree(const Tree&);
    Tree(Tree&&);
    ~Tree();
    int numberOfWord(char*);
    void add(char*);
    void remove(char*);
    int countWords();
    int findWord(char*);
    friend std::ostream& operator<< (std::ostream& out, const Tree& tree){
        out << tree.head;
        return out;
    }
    Tree& operator=(Tree& tree)
    {
        std::cout << "copy=\n";
        if (this != &tree) {
            Tree local(tree);
            std::swap(head, local.head);
            std::swap(size, local.size);
        }
        return *this;
    }
    Tree& operator=(Tree&& tree)
    {
        std::cout << "pere=\n";
        if (this != &tree) {
            std::swap(head, tree.head);
            std::swap(size, tree.size);
        }
        return *this;
    }
};
