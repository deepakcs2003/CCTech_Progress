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
    std::vector<float> getMesh3D() const override;
    

   

private:
    void rebuild(QPoint a, QPoint b);
};