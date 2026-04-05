#include "Square.h"
#include <algorithm>
#include <cmath>

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

// square to cube
std::vector<float> Square::getVertices3D(float rotY) const
{
    float cx = (pts[0].x() + pts[2].x()) / 2.0f;
    float cy = (pts[0].y() + pts[2].y()) / 2.0f;
    float s = std::abs(pts[1].x() - pts[0].x()) / 2.0f;

    // 8 cube vertices (local space)
    float v[8][3] = {
        {-s,-s,-s}, { s,-s,-s}, { s, s,-s}, {-s, s,-s},
        {-s,-s, s}, { s,-s, s}, { s, s, s}, {-s, s, s}
    };

    float rad = rotY * PI / 180.0f;
    float cosA = cosf(rad), sinA = sinf(rad);

    //  transformed vertices
    float px[8], py[8], pz[8];

    for (int i = 0; i < 8; i++)
    {
        float rx = v[i][0] * cosA - v[i][2] * sinA;
        float rz = v[i][0] * sinA + v[i][2] * cosA;

        px[i] = cx + rx;
        py[i] = cy + v[i][1];
        pz[i] = rz;
    }

    //  TRIANGLE INDICES (12 triangles)
    int idx[] = {
        0,1,2, 0,2,3,   // front
        4,5,6, 4,6,7,   // back
        0,3,7, 0,7,4,   // left
        1,2,6, 1,6,5,   // right
        3,2,6, 3,6,7,   // top
        0,1,5, 0,5,4    // bottom
    };

    std::vector<float> mesh;

    for (int i = 0; i < 36; i++) // 12 triangles × 3 vertices
    {
        int id = idx[i];

        mesh.push_back(px[id]);
        mesh.push_back(py[id] - pz[id] * 0.5f); // pseudo 3D projection
    }

    return mesh;
}