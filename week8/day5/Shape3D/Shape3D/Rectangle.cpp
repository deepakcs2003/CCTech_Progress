#include "Rectangle.h"
#include <algorithm>
#include <cmath>
#include <QDebug>


static const float PI = 3.14159265f;

Rectangle::Rectangle(QPoint s, QPoint e) {
    pts.resize(4);
    rebuild(s, e);
}

void Rectangle::setEnd(QPoint p) { rebuild(pts[3], p); }
void Rectangle::moveControlPoint(int i, QPoint p) { rebuild(p, pts[(i + 2) % 4]); }

void Rectangle::rebuild(QPoint a, QPoint b) {
    int x0 = std::min(a.x(), b.x()), x1 = std::max(a.x(), b.x());
    int y0 = std::min(a.y(), b.y()), y1 = std::max(a.y(), b.y());
    pts[0] = QPoint(x0, y1);
    pts[1] = QPoint(x1, y1);
    pts[2] = QPoint(x1, y0);
    pts[3] = QPoint(x0, y0);
}

std::vector<float> Rectangle::getVertices() const {
    std::vector<float> v;
    for (int i = 0; i < 4; i++) {
        v.push_back(pts[i].x());
        v.push_back(pts[i].y());
        v.push_back(pts[(i + 1) % 4].x());
        v.push_back(pts[(i + 1) % 4].y());
    }
    return v;
}

// rectangle to cuboid
std::vector<float> Rectangle::getVertices3D(float rotY) const
{
    float cx = (pts[0].x() + pts[2].x()) / 2.0f;
    float cy = (pts[0].y() + pts[2].y()) / 2.0f;

    float hw = std::abs(pts[1].x() - pts[0].x()) / 2.0f;
    float hh = std::abs(pts[2].y() - pts[1].y()) / 2.0f;
    float d = (hw + hh) * 0.5f;

    // 8 vertices (local space)
    float v[8][3] = {
        {-hw,-hh,-d}, { hw,-hh,-d}, { hw, hh,-d}, {-hw, hh,-d},
        {-hw,-hh, d}, { hw,-hh, d}, { hw, hh, d}, {-hw, hh, d}
    };

    float rad = rotY * PI / 180.0f;
    float cosA = cosf(rad), sinA = sinf(rad);

    // transformed vertices (world space)
    float px[8], py[8], pz[8];

    for (int i = 0; i < 8; i++)
    {
        float rx = v[i][0] * cosA - v[i][2] * sinA;
        float rz = v[i][0] * sinA + v[i][2] * cosA;

        px[i] = cx + rx;
        py[i] = cy + v[i][1];
        pz[i] = rz;
    }

    //  triangle indices
    int idx[] = {
        0,1,2, 0,2,3,  
        4,5,6, 4,6,7, 
        0,3,7, 0,7,4,  
        1,2,6, 1,6,5,  
        3,2,6, 3,6,7, 
        0,1,5, 0,5,4  
    };

    std::vector<float> mesh;

    for (int i = 0; i < 36; i++)
    {
        int id = idx[i];

        mesh.push_back(px[id]);
        mesh.push_back(py[id] - pz[id] * 0.5f); // same projection
    }
    for (int i = 0;i < mesh.size();i += 3) {
        qDebug() << mesh[i] << mesh[i + 1] << mesh[i + 2];
    }
    return mesh;
}