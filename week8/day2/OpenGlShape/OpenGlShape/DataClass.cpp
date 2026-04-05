#include "DataClass.h"
#include <QDebug>

 double DataClass::torerance=1e-6;

DataClass::DataClass()
{
	StoreData();
}

DataClass::~DataClass()
{
}

void DataClass::StoreData()
{
	std::vector<float> data = stlData->loadSTL();
	for (int i = 0;i < data.size();i += 18) {
		std::vector<int> indices;
		for (int j = i;j < i + 18;j += 6) {
			double x = data[j];
			double y = data[j + 1];
			double z = data[j + 2];
			//qDebug() << x << y<< z;
			int idx = findVertex(x, y, z);
			indices.push_back(idx);
		}
		//for (int k = 0;k < 3;k++) {
		//	qDebug() << indices[k];
		//}
		TriangleClass t(indices[0], indices[1], indices[2]);
		triangles.push_back(t);
	}
}

void DataClass::printData()
{
	qDebug() << "this is triangle vertices";
	for (auto t : triangles) {
		qDebug() << "triangle indices";
		qDebug() << t.getV1()<< t.getV2()<< t.getV3();
		VertexClass v1= vertices[t.getV1()];
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
	return fabs(x1-x2)<torerance && fabs(y1-y2)<torerance && fabs(z1-z2)<torerance;
}

int DataClass::findVertex(double x, double y, double z)
{
	for (int i = 0;i < vertices.size();i++) {
		VertexClass v = vertices[i];
		if (checkTorerance(x, y, x, v.getX(), v.getY(), v.getZ())) {
			return i;
		}
	}
	//VertexClass v(x, y, z);
	vertices.emplace_back(x, y, z);
	return vertices.size()-1;

}
