#include "fibonacci.h"
#include <ctime>

fibonacci::fibonacci(int n) :n(n)
{
}

fibonacci::~fibonacci()
{
}

std::vector<float> fibonacci::fibonacciPoint()
{
    std::vector<float> points;

    float angle = 0.0f;
    float angleStep = 0.25f; // smooth spiral

    int f = 0;
    int s = 1;

    for (int i = 0; i < n; i++)
    {
        int newPoint = f + s;

        float r = newPoint * 0.01f;  // scale control

        float x = r * cos(angle);
        float y = r * sin(angle);

        points.push_back(x);
        points.push_back(y);

        // color
        points.push_back(genCol());
        points.push_back(genCol());
        points.push_back(genCol());

        angle += angleStep;

        f = s;
        s = newPoint;
    }

    return points;
}
float fibonacci::genCol()
{
    //srand(time(0));  // seed

    float num = (rand() % 101) / 100.0f;
    return num;
}
