#include <iostream>
#include "L2List.h"
#include "Iterator.h"
using namespace std;

int main()
{
    /*L2List list;
    cout << list.getLength();
    L2List::L2Iterator it(list);
    it.start();
    cout << list.getBuffer() -> value;
    cout << "a";
    list.add(it, 1);
    cout << "b";
    it.start();
    it.next();
    list.add(it, 2);
    cout << "c";
    it.start();
    it.next();
    while(!it.finish()){
        cout <<"\n                                    a: " <<  it.get() -> value << "                       a\n";
        it.next();
    }
    //cout << list.begin().get() -> value;
    cout << list.getLength();
    return 0;*/
    L2List l;
    cout<< "a\n";
    L2List::L2Iterator it(l);
    cout<< "a\n";
    cout << l.getBuffer() -> value << "\n";
    it.start();
    cout<< "a\n";
    cout << "it.get data: " << it.get() -> value << endl;
    l.add(it,1);
    cout << "it.get data: " << it.get() -> value << endl;
    cout<< "a\n";
    it.start();
    cout << it.get() -> value;
    l.add(it,2);
    cout << "it.get data: " << it.get() -> value << endl;
    it.start();
    it.next();
    cout<<it.get()->value;
    it.next();
    cout<<it.get()->value;
    cout << "a";
    l.empty();
    L2List::L2Iterator it1(l);
    it.start();
    l.add(it1, 3);
    it1.start();
    it1.next();
    cout << "\n aaaaaa" << it1.get() -> value;
    it1.next();

    cout << "\n aaaaaa" << it1.get() -> value;
    return 0;
}
