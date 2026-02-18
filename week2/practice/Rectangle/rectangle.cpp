#include "rectangle.h"

Rectangle::Rectangle(int l,int w):length(l),width(w){};
int Rectangle::calculate_area(){
    return length*width;
}
int Rectangle::calculate_perimeter(){
    return 2*length+2*width;
}
