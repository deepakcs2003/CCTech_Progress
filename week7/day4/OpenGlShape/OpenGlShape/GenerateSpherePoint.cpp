#include "GenerateSpherePoint.h"

GenerateSpherePoint::GenerateSpherePoint(float r, float x, float y, float z)
    : radius(r), x(x), y(y), z(z)
{
}

float GenerateSpherePoint::genCol()
{
    return (rand() % 101) / 100.0f;
}
std::vector<float> GenerateSpherePoint::generatePoint()
{
    points.clear();

    float pi = 3.14159265358979323846f;
    int segment = 200;

    for (int i = 0; i <= segment; i++) {
        float lat = (float)i / segment * pi;

        for (int j = 0; j <= segment; j++) {
            float lon = (float)j / segment * 2 * pi;

            float px = x + radius * sin(lat) * cos(lon);
            float py = y + radius * sin(lat) * sin(lon);
            float pz = z + radius * cos(lat);



            // POSITION
            points.push_back(px);
            points.push_back(py);
            points.push_back(pz);

            ////  COLOR
            //int colorIndex = j % 6;

            //float r = 0, g = 0, b = 0;

            //switch (colorIndex)
            //{
            //case 0: r = 1; g = 0; b = 0; break; // red
            //case 1: r = 1; g = 1; b = 0; break; // yellow
            //case 2: r = 0; g = 1; b = 0; break; // green
            //case 3: r = 0; g = 0; b = 1; break; // blue
            //case 4: r = 1; g = 0; b = 1; break; // pink
            //case 5: r = 1; g = 0.5f; b = 0; break; // orange
            //}

            points.push_back(genCol());
            points.push_back(genCol());
        }

    }
    return points;

}
void GenerateSpherePoint::applyMatrix(QMatrix4x4& mat)
{
    for (int i = 0; i < points.size(); i += 6) {

        QVector4D v(points[i], points[i + 1], points[i + 2], 1.0f);
        v = mat * v;

        points[i] = v.x();
        points[i + 1] = v.y();
        points[i + 2] = v.z();
    }
}
std::vector<float> GenerateSpherePoint::rotateOrigin(float angle, float ax, float ay, float az)
{
    QMatrix4x4 mat;
    mat.setToIdentity();
    mat.rotate(angle, ax, ay, az);

    applyMatrix(mat);
    return points;
}

std::vector<float> GenerateSpherePoint::rotateSelf(float angle, float ax, float ay, float az)
{
    QMatrix4x4 mat;
    mat.setToIdentity();

    mat.translate(x, y, z);
    mat.rotate(angle, ax, ay, az);
    mat.translate(-x, -y, -z);

    applyMatrix(mat);
    return points;
}

std::vector<float> GenerateSpherePoint::scaleOrigin(float sx, float sy, float sz)
{
    QMatrix4x4 mat;
    mat.setToIdentity();
    mat.scale(sx, sy, sz);

    applyMatrix(mat);
    return points;
}

std::vector<float> GenerateSpherePoint::scaleSelf(float sx, float sy, float sz)
{
    QMatrix4x4 mat;
    mat.setToIdentity();

    mat.translate(x, y, z);
    mat.scale(sx, sy, sz);
    mat.translate(-x, -y, -z);

    applyMatrix(mat);
    return points;
}

std::vector<float> GenerateSpherePoint::translationOrigin(float dx, float dy, float dz)
{
    QMatrix4x4 mat;
    mat.setToIdentity();
    mat.translate(dx, dy, dz);

    applyMatrix(mat);

    // update center also
    x += dx;
    y += dy;
    z += dz;

    return points;
}

std::vector<float> GenerateSpherePoint::translationSelf(float dx, float dy, float dz)
{
    return translationOrigin(dx, dy, dz);
}