#include <iostream>
#include "boxClass.h"
#include "Container.h"

using namespace std;
using namespace Container_Box;
int test2();
int test3();
int test4();
int test5();
int test67();
int test11();
int testMaxWeight();

int main()
{
    testMaxWeight();
    return 0;
}

int test2() {
    int size = 5;
    Box box1(5, 5, 5, 10.5, 20);
    Box box2(2, 1, 3, 17, 120);
    Box box3(5, 6, 5, 16, 50);
    Box box4(1, 5, 5, 5, 30);
    Box box5 = Box(3, 1, 42, 10.5, 100);

    Box *boxs = new Box[size];
    boxs[0] = box1;
    boxs[1] = box2;
    boxs[2] = box3;
    boxs[3] = box4;
    boxs[4] = box5;

    int summa = summa_value_of_boxs(boxs, size);
    cout << summa;
    return 0;
}

int test3(){
    int size = 5;
    Box box1(5, 5, 5, 10.5, 20);
    Box box2(2, 1, 3, 17, 120);
    Box box3(5, 6, 5, 16, 50);
    Box box4(1, 5, 5, 5, 30);
    Box box5(3, 1, 4, 10.5, 100);

    Box *boxs = new Box[size];
    boxs[0] = box1;
    boxs[1] = box2;
    boxs[2] = box3;
    boxs[3] = box4;
    boxs[4] = box5;

    cout << summa_sides_lower_value(boxs, size, 10);
}

int test4(){
    int size = 5;
    Box box1 = Box(5, 5, 5, 12, 20);
    Box box2 = Box(2, 1, 3, 17, 120);
    Box box3 = Box(5, 6, 5, 16, 50);
    Box box4 = Box(1, 5, 5, 5, 30);
    Box box5 = Box(3, 1, 4, 10.5, 100);

    Box *boxs = new Box[size];
    boxs[0] = box1;
    boxs[1] = box2;
    boxs[2] = box3;
    boxs[3] = box4;
    boxs[4] = box5;

    cout << max_weight_lower_maxV(boxs, size, 15);
}

int test5(){
    int size = 5;
    Box box1 = Box(1, 1, 1, 10.5, 20);
    Box box2 = Box(4, 4, 4, 17, 120);
    Box box3 = Box(5, 5, 5, 16, 50);
    Box box4 = Box(7, 7, 7, 5, 30);
    Box box5 = Box(6, 6, 6, 10.5, 100);

    Box *boxs = new Box[size];
    boxs[0] = box1;
    boxs[1] = box2;
    boxs[2] = box3;
    boxs[3] = box4;
    boxs[4] = box5;

    cout << (boxs_int_boxs(boxs, size));
}

int test67(){
    Box box1;
    Box box2;
    cout << "box1 ";
    cin >> box1;
    cout << "box2 ";
    cin >> box2;
    cout << "box1 == box2: " << (box1 == box2) << endl;
    cout << "box1 != box2: " << (box1 != box2) << endl;
    cout << box1 << endl << box2;
}

int test11(){
    Container con(1, 1, 1, 10);
    Box box1(1, 1, 1, 3, 5);
    cout << box1 << endl;
    Box box2(2, 2, 1, 4, 8);
    cout << box2 << endl;
    con.add_box(box1);
    con.add_box(box2);
    cout << "Container size: " << con.size() << endl;
    cout << "Container weight: " << con.get_sum_weight() << endl;
    cout << "Container sum value: " << con.get_sum_value() << endl;
    cout << con.get_box(1) << endl;
    cout << con[0] << endl;
    con.delete_box(0);
    cout << con;
}

int testMaxWeight(){
    Container con;
    cin >> con;
    try{
        Box box1(1, 1, 1, 3, 5);
        Box box2(2, 2, 1, 4, 8);
        Box box3(2, 2, 3, 5, 8);
        con.add_box(box1);
        con.add_box(box2);
        con.add_box(box3);
    }catch(invalid_argument& e){
        cout << e.what() << endl;
    }
}


