#include <iostream>
#include "tree.h"
using namespace std;

int main()
{
    Tree tree;
    tree.add("b");
    tree.add("a");
    tree.add("a");
    tree.add("c");
    tree.remove("b");
    tree.add("d");
    cout << tree.countWords() << endl;
    cout << tree.findWord("a") << endl;
    cout << tree;
    return 0;
}
