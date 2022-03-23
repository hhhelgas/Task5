#ifndef BOX_H_
#define BOX_H_
#include <iostream>
namespace Container_Box {
    class Box {
        private:
            int length;
            int width;
            int height;
            double weight;
            int value;
        public:
            Box(){
               length = 0;
               width = 0;
               height = 0;
               weight = 0;
               value = 0;
            }

            Box(int n_length, int n_width, int n_height, double n_weight, int n_value){
               length = n_length;
               width = n_width;
               height = n_height;
               weight = n_weight;
               value = n_value;
            }

            void setLength(int n_length){
                length = n_length;
            }

            int getLength() const{
                return length;
            }

            void setHeight(int n_height){
                height = n_height;
            }

            int getHeight() const{
                return height;
            }

            void setWidth(int n_width){
                width = n_width;
            }

            int getWidth() const{
                return width;
            }

            void setWeight(double n_weight){
                weight = n_weight;
            }

            double getWeight() const{
                return weight;
            }

            void setValue(double n_value){
                value = n_value;
            }

            double getValue() const{
                return value;
            }

            bool operator== (const Box &box2){
                return (this->length == box2.length && this->height == box2.height && this->value == box2.value && this->weight == box2.weight && this->width == box2.width);
            }

            bool operator!= (const Box &box2){
                return !(this->length == box2.length && this->height == box2.height && this->value == box2.value && this->weight == box2.weight && this->width == box2.width);
            }
            friend std::ostream& operator<< (std::ostream &out, const Box& box){
                return out << "Box: {" << box.getLength() << ", " << box.getWidth() << ", " << box.getHeight() << ", " << box.getWeight() << ", " << box.getValue() << "}";
            }
            friend std::istream& operator>> (std::istream &in, Box& box){
                in >> box.length >> box.width >> box.height >> box.weight >> box.value;
                return in;
            }

    };
    int summa_value_of_boxs(Box*, int);
    bool summa_sides_lower_value(Box*, int, int);
    double max_weight_lower_maxV(Box*, int, int);
    bool boxs_int_boxs(Box*, int);



}
#endif
