#pragma once
#include "AreaShape.h"
#include "Point.h"
class Circle :
    public AreaShape
{
private:
    static double pi;
    Point center;
    double radius;
public:
    Circle(int id, double x,double y, double r);
    void move(double dx, double dy) override;
    void scale(double factor) override;
    std::string getType() const override;
    void display() const override;

    double area() const override;
    double perimeter() const override;

    bool contains(const Point& p) const;
};

