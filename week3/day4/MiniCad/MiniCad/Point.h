#pragma once
#include "Shape.h"
class Point :
    public Shape
{
private:
    double x;
    double y;
public:
    Point(int id, double x, double y);
    void move(double dx, double dy) override;
    void scale(double factor) override;
    std::string getType() const override;
    void display() const override;
    double getX() const;
    double getY() const;
    double distanceTo(const Point& other) const;
};

