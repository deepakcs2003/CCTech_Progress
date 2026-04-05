#pragma once
#include <QPoint>
#include <vector>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;

    virtual std::string name() const = 0;
    virtual void setEnd(QPoint p) = 0;
    virtual std::vector<float> getVertices() const = 0;
    virtual std::vector<QPoint> getControlPoints() const = 0;
    virtual void moveControlPoint(int idx, QPoint p) = 0;
    virtual std::vector<float> getVertices3D(float rotY) const = 0;

    int nearestControlPoint(QPoint pos, float tol) const {
        for (int i = 0; i < (int)pts.size(); i++) {
            float dx = pts[i].x() - pos.x();
            float dy = pts[i].y() - pos.y();
            if (dx * dx + dy * dy < tol *10)
                return i;
        }
        return -1;
    }

protected:
    std::vector<QPoint> pts;
};