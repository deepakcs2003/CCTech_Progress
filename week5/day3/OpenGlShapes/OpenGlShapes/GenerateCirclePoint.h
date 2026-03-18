#pragma once
#include<vector>
class GenerateCirclePoint
{
private:
	float radius;
	float x;
	float y;
public:
	GenerateCirclePoint(float radius, float x,float y);
	std::vector<float> generatePoint();
};

