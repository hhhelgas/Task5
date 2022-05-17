#include <iostream>
#include "tree.h"
using namespace std;

int main()
{
    Tree tree;
    tree.add("b");
    tree.add("aa");
    tree.add("a");
    tree.add("c");
    cout << tree << endl;
    cout << tree.countWords() << endl;
    tree.remove("b");
    cout << tree.countWords() << endl;
    tree.add("d");
    cout << tree.countWords() << endl;
    cout << tree.findWord("a") << endl;
    cout << tree << endl;
    Tree new_tree = tree;
    cout << new_tree;
    new_tree = tree;
    return 0;
}
