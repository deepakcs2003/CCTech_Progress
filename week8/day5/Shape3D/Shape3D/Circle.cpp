#include "Circle.h"
#include <cmath>
#include <algorithm>

static const float PI = 3.14159265f;

Circle::Circle(QPoint s, QPoint e) : m_start(s) {
    pts.resize(2);
    setEnd(e);
}

void Circle::setEnd(QPoint p) {
    QPoint center((m_start.x() + p.x()) / 2, (m_start.y() + p.y()) / 2);
    int r = std::min(std::abs(p.x() - m_start.x()), std::abs(p.y() - m_start.y())) / 2;
    pts[0] = center;
    pts[1] = QPoint(center.x() + std::max(1, r), center.y());
}

void Circle::moveControlPoint(int i, QPoint p) {
    if (i == 0) {
        QPoint diff = p - pts[0];
        pts[0] = p;
        pts[1] += diff;
    }
    else {
        int dx = p.x() - pts[0].x();
        int dy = p.y() - pts[0].y();
        int r = std::max(1, (int)std::sqrt(dx * dx + dy * dy));
        pts[1] = QPoint(pts[0].x() + r, pts[0].y());
    }
}

std::vector<float> Circle::getVertices() const {
    std::vector<float> v;
    float cx = pts[0].x(), cy = pts[0].y();
    float r = pts[1].x() - pts[0].x();
    for (int i = 0; i < SEG; i++) {
        float t1 = 2 * PI * i / SEG, t2 = 2 * PI * (i + 1) / SEG;
        v.push_back(cx + r * cosf(t1)); v.push_back(cy + r * sinf(t1));
        v.push_back(cx + r * cosf(t2)); v.push_back(cy + r * sinf(t2));
    }
    return v;
}

// circle to sphere 
std::vector<float> Circle::getVertices3D(float rotY) const
{
    float cx = pts[0].x();
    float cy = pts[0].y();
    float r = pts[1].x() - pts[0].x();

    std::vector<float> mesh;

    const int LAT = 30;
    const int LON = 30;

    for (int i = 0; i < LAT; i++)
    {
        float t1 = PI * i / LAT - PI / 2;
        float t2 = PI * (i + 1) / LAT - PI / 2;

        for (int j = 0; j < LON; j++)
        {
            float p1 = 2 * PI * j / LON;
            float p2 = 2 * PI * (j + 1) / LON;

            // 4 points
            float x1 = r * cosf(t1) * cosf(p1);
            float y1 = r * sinf(t1);
            float z1 = r * cosf(t1) * sinf(p1);

            float x2 = r * cosf(t1) * cosf(p2);
            float y2 = r * sinf(t1);
            float z2 = r * cosf(t1) * sinf(p2);

            float x3 = r * cosf(t2) * cosf(p1);
            float y3 = r * sinf(t2);
            float z3 = r * cosf(t2) * sinf(p1);

            float x4 = r * cosf(t2) * cosf(p2);
            float y4 = r * sinf(t2);
            float z4 = r * cosf(t2) * sinf(p2);

            //  projection
            float ox1 = cx + x1;
            float oy1 = cy + y1 - z1 * 0.5f;

            float ox2 = cx + x2;
            float oy2 = cy + y2 - z2 * 0.5f;

            float ox3 = cx + x3;
            float oy3 = cy + y3 - z3 * 0.5f;

            float ox4 = cx + x4;
            float oy4 = cy + y4 - z4 * 0.5f;

            // triangles
            mesh.push_back(ox1); mesh.push_back(oy1);
            mesh.push_back(ox2); mesh.push_back(oy2);
            mesh.push_back(ox3); mesh.push_back(oy3);

            mesh.push_back(ox2); mesh.push_back(oy2);
            mesh.push_back(ox4); mesh.push_back(oy4);
            mesh.push_back(ox3); mesh.push_back(oy3);
        }
    }

    return mesh;
}