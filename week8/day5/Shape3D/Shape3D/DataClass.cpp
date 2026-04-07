#include "DataClass.h"
#include <QDebug>
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
			int idx;
			double x = data[j];
			double y = data[j + 1];
			double z = data[j + 2];
			//qDebug() << x << y<< z;
			auto vertex = std::make_tuple(x, y, z);
			if (IdxMap.count(vertex) < 1) {
				VertexClass v(x, y, z);
				idx = vertices.size();
				IdxMap[vertex] = idx;
				vertices.push_back(v);
			}
			else {
				idx = IdxMap[vertex];
			}
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
