#pragma once
#include <vector>
class GenerateCubePoint
{
	private:
	float length;
	float x;
	float y;
	float z;

public:
	GenerateCubePoint(float length, float x, float y, float z);
	std::vector<float> generatePoint();
	float genCol();
	void rotateOrigin();
	void rotateSelf();
	void scaleOrigin();
	void scaleSelf();
	void translationOrigin();
	void translationSelf();
};

