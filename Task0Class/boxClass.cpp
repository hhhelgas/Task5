#include <iostream>
#include "boxClass.h"

using namespace std;
using namespace Container_Box;


int Container_Box::summa_value_of_boxs(Box* box, int size){
    int summa = 0;

    for(int i = 0; i < size; i++) {
        summa += box[i].getValue();
    }

    return summa;
}

bool Container_Box::summa_sides_lower_value(Box* box, int size, int value){
    int summa_sides = 0;
    for(int i = 0; i < size; i++) {
        summa_sides += box[i].getHeight() + box[i].getLength() + box[i].getWidth();
    }
    return summa_sides < value;
}

double Container_Box::max_weight_lower_maxV(Box* box, int size, int maxV)

{
    double max_weight = -1;

    for(int i = 0; i < size; i++) {
        cout << box[i].getWeight() << " ";
        if(box[i].getWeight() < maxV && max_weight < box[i].getWeight()){
            max_weight = box[i].getWeight();
        }
    }
    cout << endl;
    return max_weight;
}

bool Container_Box::boxs_int_boxs(Box* box, int size) {
    bool check = true;
    for(int i = 0; i < size-1; i++) {
        for(int j = i + 1; j < size; j++){
            if(!((box[i].getHeight() < box[j].getHeight() && box[i].getWidth() < box[j].getWidth() && box[i].getLength() < box[j].getLength()) ||
                  (box[i].getHeight() > box[j].getHeight() && box[i].getWidth() > box[j].getWidth() && box[i].getLength() > box[j].getLength()))){
                check = false;
                break;
            }else{
                continue;
            }
        }
    }
    return check;
}
