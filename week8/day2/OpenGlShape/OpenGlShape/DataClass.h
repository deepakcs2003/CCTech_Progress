#pragma once
#include <VertexClass.h>
#include <TriangleClass.h>
#include <vector>
#include <map>
#include <tuple>
#include <STL_ASCII.h>
class DataClass
{
private:
	static double torerance;
public:
	DataClass();
	~DataClass();
	std::vector<VertexClass> vertices;
	std::vector<TriangleClass> triangles;
	//std::map<std::tuple<double, double, double>, int> IdxMap;
	STL_ASCII* stlData;
	void StoreData();
	void printData();
	bool checkTorerance(double x1, double y1, double z1, double x2, double y2, double z3);
	int findVertex(double x, double y, double z);
};

