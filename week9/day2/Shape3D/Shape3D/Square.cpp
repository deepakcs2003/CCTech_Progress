#include "Square.h"
#include <algorithm>
#include <cmath>
#include <QDebug>

static const float PI = 3.14159265f;

Square::Square(QPoint s, QPoint e) : m_anchor(s) {
    pts.resize(4);
    rebuild(s, e);
}

void Square::setEnd(QPoint p) { rebuild(m_anchor, p); }
void Square::moveControlPoint(int i, QPoint p) { rebuild(pts[(i + 2) % 4], p); }

void Square::rebuild(QPoint a, QPoint b) {
    int side = std::min(std::abs(b.x() - a.x()), std::abs(b.y() - a.y()));
    int sx = (b.x() >= a.x()) ? side : -side;
    int sy = (b.y() >= a.y()) ? side : -side;
    int x0 = std::min(a.x(), a.x() + sx);
    int y0 = std::min(a.y(), a.y() + sy);
    pts[0] = QPoint(x0, y0 + side);
    pts[1] = QPoint(x0 + side, y0 + side);
    pts[2] = QPoint(x0 + side, y0);
    pts[3] = QPoint(x0, y0);
}

std::vector<float> Square::getVertices() const {
    std::vector<float> v;
    for (int i = 0; i < 4; i++) {
        v.push_back(pts[i].x());        v.push_back(pts[i].y());
        v.push_back(pts[(i + 1) % 4].x());  v.push_back(pts[(i + 1) % 4].y());
    }
    return v;
}

std::vector<float> Square::getMesh3D() const
{
    float cx = (pts[0].x() + pts[2].x()) / 2.0f;
    float cy = (pts[0].y() + pts[2].y()) / 2.0f;
    float s = std::abs(pts[1].x() - pts[0].x()) / 2.0f;

    float v[8][3] = {
        {-s,-s,-s}, { s,-s,-s}, { s, s,-s}, {-s, s,-s},
        {-s,-s, s}, { s,-s, s}, { s, s, s}, {-s, s, s}
    };

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

        mesh.push_back(cx + v[id][0]);
        mesh.push_back(cy + v[id][1]);
        mesh.push_back(v[id][2]); 
    }

    return mesh;
}

