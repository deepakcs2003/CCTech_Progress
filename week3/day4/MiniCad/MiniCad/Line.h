#pragma once
#include <string>
#include "Point.h"
using namespace std;

class Line :
    public Shape
{
private:
    Point p1;
    Point p2;
public:
    Line(int id,double x1, double y1, double x2, double y2);
    void move(double dx, double dy) override;
    void scale(double factor) override;
    std::string getType() const override;
    void display() const override;

    double length() const;
};

