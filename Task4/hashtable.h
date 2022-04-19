struct Node{
    int key;
    int value;
    Node* next;
}

class Hashtable{

public:
    virtual void add(){}
    virtual void remove(){}
    virtual int indexOf(){}
    virtual void empty(){}
    virtual bool isEmpty(){}
};
