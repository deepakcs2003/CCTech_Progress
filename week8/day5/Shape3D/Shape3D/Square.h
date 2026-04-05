#pragma once
#include "Shape.h"

class Square : public Shape {
public:
    Square(QPoint s, QPoint e);

    std::string name() const override { return "Square"; }
    void setEnd(QPoint p) override;
    std::vector<float> getVertices() const override;
    std::vector<QPoint> getControlPoints() const override { return pts; }
    void moveControlPoint(int idx, QPoint p) override;

    // square to cube
    std::vector<float> getVertices3D(float rotY) const override;

private:
    QPoint m_anchor;
    void rebuild(QPoint anchor, QPoint drag);
};