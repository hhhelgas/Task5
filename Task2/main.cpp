#include <iostream>
#include "queue.h"
#include "iterator.h"
using namespace std;

int main()
{
    Queue queue(4);
    try{
        queue.add(1);
        queue.add(2);
        queue.add(3);
        //cout << "delete: " << queue.pop() << endl;
        cout << "length: " << queue.size() << endl;
        queue.add(4);
        cout << "begin elem: " << queue.get() << endl;

        cout << "start iterator\n";
        Iterator it(queue);
        while(!it.finish()){
            cout << it.getValue() << " ";
            it.next();
        }
        cout << "\nfinish iterator\n";
        cout << "delete: " << queue.pop() << endl;
        queue.add(5);

        Iterator it1(queue);
        while(!it1.finish()){
            cout << it1.getValue() << " ";
            it1.next();
        }

        cout << "is empty? " << queue.isEmpty() << endl;
        queue.empty();
        cout << "is empty? " << queue.isEmpty() << endl;

    }catch(invalid_argument& e){
        cout << endl << e.what() << endl;
    }
    return 0;
}
