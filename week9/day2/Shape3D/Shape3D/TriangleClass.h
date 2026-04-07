#pragma once
class TriangleClass
{
private:
	int v1, v2, v3;
public:
	TriangleClass(int v1, int v2, int v3);
	~TriangleClass();
	int getV1() const;
	int getV2() const;
	int getV3() const;
};

