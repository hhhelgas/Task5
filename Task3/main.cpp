#include <iostream>
#include "L2List.h"
#include "Iterator.h"
using namespace std;

int main()
{
    L2List list;
    cout << list.getLength();
    cout << list.getBuffer() -> value;
    cout << "a";
    list.add(list.begin(), 1);
    cout << "b";
    list.add(list.begin(), 2);
    cout << "c";
    L2List::L2Iterator it(list);
    it.start();
    it.next();
    while(!it.finish()){
        cout <<"\n                                    a: " <<  it.get() -> value << "                       a\n";
        it.next();
    }
    //cout << list.begin().get() -> value;
    cout << list.getLength();
    return 0;
}
