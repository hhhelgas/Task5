#include <iostream>
#include "L2List.h"
#include "Iterator.h"
using namespace std;

int main()
{
    L2List l;
    Iterator* it = new L2List::L2Iterator(l);
    it->start();
    l.add(it, 3);
    l.add(it, 2);
    l.add(it, 1);

    it = new L2List::L2Iterator(l);
    it -> start();

    while(!it -> finish()){

        it -> next();
        cout << it -> get() -> value << " ";
    }

    it = l.begin();
    cout << "\n" << it -> get()->value << "\n";


    it = l.indexOf(4);
    if(it != nullptr){
        l.remove(it);
    }
    else{
        cout << "nullptr" << "\n";
    }


    it = new L2List::L2Iterator(l);
    it -> start();
    while(!it -> finish()) {
        it -> next();
        cout << it -> get() -> value << " ";
    }
    cout << endl;

    L2List n_list(l);
    n_list.add(n_list.begin(), 5);

    it = new L2List::L2Iterator(n_list);
    it -> start();
    while (!it -> finish()){
        it -> next();
        cout << it -> get() -> value << " ";
    }
    cout << endl;

    it = new L2List::L2Iterator(l);
    it -> start();
    while (!it -> finish()){
        it -> next();
        cout << it -> get() -> value << " ";
    }
    cout << endl;

    n_list = l;

    it = new L2List::L2Iterator(n_list);
    it -> start();
    while (!it -> finish()){
        it -> next();
        cout << it -> get() -> value << " ";
    }
    cout << endl;

    return 0;
}
