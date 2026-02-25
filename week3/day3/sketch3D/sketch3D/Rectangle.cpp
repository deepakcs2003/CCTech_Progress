#include "Rectangle.h"
#include <cmath>    // corrected header (was <math>)
#include <iostream>
#include "Shape.h"

using namespace std;

Rectangle::Rectangle(string name, double x1, double y1, double x2, double y2) :
    shape(name), x1(x1), y1(y1), x2(x2), y2(y2)
{
}

double Rectangle::area()
{
    double width = abs(x1 - x2);
    double length = abs(y1 - y2);
    return length*width;
}

void Rectangle::display()
{
    cout << name
        <<"(width=" << abs(x1 - x2)
        << ",height=" << abs(y1 - y2) << ")" << endl;
}
