#include <iostream>
#include "box.h"
using namespace std;
Box::Box(){
   length = 0;
   width = 0;
   height = 0;
   weight = 0;
   value = 0;
}

Box::Box(int n_length, int n_width, int n_height, double n_weight, int n_value){
   length = n_length;
   width = n_width;
   height = n_height;
   weight = n_weight;
   value = n_value;
}

bool operator== (const Box &box1, const Box &box2){
    return (box1.length == box2.length && box1.height == box2.height && box1.value == box2.value && box1.weight == box2.weight && box1.width == box2.width);
}

bool operator!= (const Box &box1, const Box &box2){
    return !(box1 == box2);
}

ostream& operator<< (ostream &out, const Box &box){
    out << "Box: {" << box.length << ", " << box.width << ", " << box.height << ", " << box.weight << ", " << box.value << "}";

    return out;
}

istream& operator>> (istream &in, Box &box){
    in >> box.length >> box.width >> box.height >> box.weight >> box.value;
    return in;
}


int summa_value_of_boxs(Box* box, int size){
    int summa = 0;

    for(int i = 0; i < size; i++) {
        summa += box[i].value;
    }

    return summa;
}

bool summa_sides_lower_value(Box* box, int size, int value){
    bool check = true;

    for(int i = 0; i < size; i++) {
        int summa_sides = box[i].height + box[i].length + box[i].width;
        if(summa_sides >= value){
            check = false;
            break;
        }
    }

    return check;
}

double max_weight_lower_maxV(Box* box, int size, int maxV)

{
    double max_weight = -1;

    for(int i = 0; i < size; i++) {
        cout << box[i].weight << " ";
        if(box[i].weight < maxV && max_weight < box[i].weight){
            max_weight = box[i].weight;
        }
    }
    cout << endl;
    return max_weight;
}

bool boxs_int_boxs(Box* box, int size) {
    bool check = true;
    for(int i = 0; i < size-1; i++) {
        for(int j = i + 1; j < size; j++){
            if(!((box[i].height < box[j].height && box[i].width < box[j].width && box[i].length < box[j].length) || (box[i].height > box[j].height && box[i].width > box[j].width && box[i].length > box[j].length))){
                check = false;
                break;
            }else{
                continue;
            }
        }
    }
    return check;
}
