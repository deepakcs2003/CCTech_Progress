#include "DataClass.h"
#include <QDebug>

double DataClass::torerance = 1e-6;

DataClass::DataClass()
{

}

DataClass::~DataClass()
{
}

void DataClass::StoreData(std::vector<float> data)
{
	vertices.clear();  
	triangles.clear();

	for (int i = 0; i < data.size(); i += 9) {
		std::vector<int> indices;

		for (int j = i; j < i + 9; j += 3) {
			double x = data[j];
			double y = data[j + 1];
			double z = data[j + 2];

			int idx = findVertex(x, y, z);
			indices.push_back(idx);
		}

		if (indices.size() == 3)
		{
			TriangleClass t(indices[0], indices[1], indices[2]);
			triangles.push_back(t);
		}
	}
}

void DataClass::printData()
{
	qDebug() << "this is triangle vertices";

	// 0 1 2 3 4 5 6 7 vertex index; 8*3-24
	//0-x,y,z
	//1-x,y,z
	//2-

	//0 1 2 3 4 5 6 7 8 9 10 11  12*8=96 36*36
	//0-0 1 2
	//1-1 0 2
	//2-2 3 1

	for (auto t : triangles) {
		qDebug() << "triangle indices";
		qDebug() << t.getV1() << t.getV2() << t.getV3();
		VertexClass v1 = vertices[t.getV1()];
		VertexClass v2 = vertices[t.getV2()];
		VertexClass v3 = vertices[t.getV3()];

		qDebug() << "traingle vertex";
		qDebug() << v1.getX() << v1.getY() << v1.getZ();
		qDebug() << v2.getX() << v2.getY() << v2.getZ();
		qDebug() << v3.getX() << v3.getY() << v3.getZ();


	}
}

bool DataClass::checkTorerance(double x1, double y1, double z1, double x2, double y2, double z2)
{
	return fabs(x1 - x2) < torerance && fabs(y1 - y2) < torerance && fabs(z1 - z2) < torerance;
}

int DataClass::findVertex(double x, double y, double z)
{
	for (int i = 0;i < vertices.size();i++) {
		VertexClass v = vertices[i];
		if (checkTorerance(x, y, z, v.getX(), v.getY(), v.getZ())) {
			return i;
		}
	}
	//VertexClass v(x, y, z);
	vertices.emplace_back(x, y, z);
	return vertices.size() - 1;

}

std::vector<float> DataClass::getData()  const
{
	std::vector<float> data;

	for (auto& t : triangles)
	{
		VertexClass v1 = vertices[t.getV1()];
		VertexClass v2 = vertices[t.getV2()];
		VertexClass v3 = vertices[t.getV3()];

		data.push_back((float)v1.getX());
		data.push_back((float)v1.getY());
		data.push_back((float)v1.getZ());

		data.push_back((float)v2.getX());
		data.push_back((float)v2.getY());
		data.push_back((float)v2.getZ());

		data.push_back((float)v3.getX());
		data.push_back((float)v3.getY());
		data.push_back((float)v3.getZ());
	}

	return data;
}
