#pragma once
#include "AreaShape.h"
#include <string>
#include "Point.h"
class Triangle :
    public AreaShape
{
private:
    Point p1;
    Point p2;
    Point p3;

public:
    Triangle(int id, double x1,double y1,double x2,double y2,double x3,double y3);
    void move(double dx, double dy) override;
    void scale(double factor) override;
    std::string getType() const override;
    void display() const override;

    double area() const override;
    double perimeter() const override;

    bool isValid() const;
};

