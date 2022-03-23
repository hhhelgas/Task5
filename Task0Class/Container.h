#ifndef CONTAINER_H
#define CONTAINER_H

#include "boxClass.h"
#include <vector>


namespace Container_Box{
    class Container
    {
        private:
            int length;
            int width;
            int height;
            double maxWeight;
            std::vector<Box> boxs;
        public:
            Container();
            Container(int n_length, int n_width, int n_height, double n_max_weight);
            int getLength() const{
                return length;
            }
            int getWidth() const {
                return width;
            }
            int getHeight() const {
                return height;
            }
            double getMaxWeight() const {
                return maxWeight;
            }
            int size() const;
            Box operator[] (int i){
                return boxs.at(i);
            }
            double get_sum_weight();
            int get_sum_value();
            Box get_box(int) const;
            void add_box(Box&);
            void delete_box(int i){
                if(i < size()){
                    auto n = boxs.begin() + i;
                    boxs.erase(n);
                }
            }
            friend std::ostream& operator<< (std::ostream &out, const Container& con){
                out << "Container: {" << con.getLength() << ", " << con.getWidth() << ", " << con.getHeight() << ", " << con.getMaxWeight() << std::endl;
                for(int i = 0; i < con.size(); i++) {
                    out << "    " << con.get_box(i);
                }
                out << "}";
                return out;
            }
            friend std::istream& operator>> (std::istream &in, Container& con){
                in >> con.length >> con.width >> con.height >> con.maxWeight;
                return in;
            }
    };

}
#endif // CONTAINER_H
