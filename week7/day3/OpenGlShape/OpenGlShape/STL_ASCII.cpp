#include "STL_ASCII.h"
#include <fstream>
#include <string>
#include <QString>
#include <QDebug>
#include <sstream>


STL_ASCII::STL_ASCII()
{
}

STL_ASCII::~STL_ASCII()
{
}

std::vector<float> STL_ASCII::loadSTL()
{

    std::vector<float> points;
    std::ifstream fin("../block100.stl");
    if (!fin) {
        qDebug() << "can't open file";
        return points;
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::vector<std::string> str;
        std::stringstream ss(line);
        std::string word;
        while (ss >> word) {
            str.push_back(word);
        }
        if (str[0]=="facet") {
            float ni = std::stof(str[2]);
            float nj = std::stof(str[3]);
            float nk = std::stof(str[4]);
            //qDebug() << ni << nj << nk;
        }
        else if (str[0]=="vertex") {
            float v1 = std::stof(str[1]);
            float v2 = std::stof(str[2]);
            float v3 = std::stof(str[3]);
            points.push_back(v1*0.01f);
            points.push_back(v2*0.01f);
            points.push_back(v3*0.01f);

            // points.push_back(v1);
            //points.push_back(v2);
            //points.push_back(v3);

            points.push_back(1);
            points.push_back(0);
            points.push_back(0);
            //qDebug() << v1 << v2 << v3;
        }
        //else if (str[0]=="endloop") {
        //   
        //}
    }
    return points;
}

float STL_ASCII::genCol()
{
    return (rand() % 101) / 100.0f;

}
