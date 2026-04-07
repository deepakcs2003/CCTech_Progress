#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(QPoint s, QPoint e);

    std::string name() const override { return "Circle"; }
    void setEnd(QPoint p) override;
    std::vector<float> getVertices() const override;
    std::vector<QPoint> getControlPoints() const override { return pts; }
    void moveControlPoint(int idx, QPoint p) override;
    std::vector<float> getMesh3D() const override;

    
private:
    QPoint m_start;
    static constexpr int SEG = 60;
    void rebuild(QPoint center, int radius);
};