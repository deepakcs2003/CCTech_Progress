#pragma once
class VertexClass
{
private:
	double x, y, z;
public:
	VertexClass(double x, double y, double z);
	~VertexClass();
	double getX() const;
	double getY() const;
	double getZ() const;
};

