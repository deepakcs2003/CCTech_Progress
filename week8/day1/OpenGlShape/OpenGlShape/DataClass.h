#pragma once
#include <VertexClass.h>
#include <TriangleClass.h>
#include <vector>
#include <map>
#include <tuple>
#include <STL_ASCII.h>
class DataClass
{
public:
	DataClass();
	~DataClass();
	std::vector<VertexClass> vertices;
	std::vector<TriangleClass> triangles;
	std::map<std::tuple<double, double, double>, int> IdxMap;
	STL_ASCII* stlData;
	void StoreData();
	void printData();
};

