#include <iostream>
#include "Container.h"
#include <vector>
using namespace std;
using namespace Container_Box;

Container::Container()
{
    height = 0;
    width = 0;
    length = 0;
    maxWeight = 0;
}

Container::Container(int n_length, int n_width, int n_height, double n_maxWeight)
{
    height = n_height;
    width = n_width;
    length = n_length;
    maxWeight = n_maxWeight;
}

int Container::size() const{
    return boxs.size();
}

//Box operator[] (int i){
//    return boxs.at(i);
//}

double Container::get_sum_weight(){
    double sum_weight = 0;
    for(int i = 0; i < size(); i++){
        sum_weight += boxs.at(i).getWeight();
    }
    return sum_weight;
}

int Container::get_sum_value(){
    int sum_value = 0;
    for(int i = 0; i < boxs.size(); i++){
        sum_value += boxs.at(i).getValue();
    }
    return sum_value;
}

Box Container::get_box(int i) const{
    return boxs.at(i);
}

void Container::add_box(Box& box){
    if((get_sum_weight() + box.getWeight()) <= maxWeight){
        boxs.push_back(box);
    } else {
        throw invalid_argument("total weight > max weight");
    }
}


