#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(QPoint s, QPoint e);

    std::string name() const override { return "Rectangle"; }
    void setEnd(QPoint p) override;
    std::vector<float> getVertices() const override;
    std::vector<QPoint> getControlPoints() const override { return pts; }
    void moveControlPoint(int idx, QPoint p) override;

    // rectangle -> cuboid
    std::vector<float> getVertices3D(float rotY) const override;

private:
    void rebuild(QPoint a, QPoint b);
};