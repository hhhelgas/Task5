#include <iostream>
using namespace std;
struct Box {
    int length;
    int width;
    int height;
    double weight;
    int value;

    Box();
    Box(int n_length, int n_width, int n_height, double n_weight, int n_value);

    friend bool operator== (const Box &box1, const Box &box2);
    friend bool operator!= (const Box &box1, const Box &box2);
    friend ostream& operator<< (ostream &out, const Box &box);
    friend istream& operator>> (istream &in, Box &box);
};

int summa_value_of_boxs(Box*, int);
bool summa_sides_lower_value(Box*, int, int);
double max_weight_lower_maxV(Box*, int, int);
bool boxs_int_boxs(Box*, int);
