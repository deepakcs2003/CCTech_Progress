#pragma once
#include <vector>
class GenerateLinePoint
{

private:
	float slope;
	float contant;
public:
	GenerateLinePoint(float m, float c);
	std::vector<float> generatePoint();
};

