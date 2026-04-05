
#include "STL_Binary.h"
#include <fstream>
#include <QDebug>
#include <iostream>
STL_Binary::STL_Binary()
{
}

STL_Binary::~STL_Binary()
{
}

std::vector<float> STL_Binary::loadSTL()
{
    //"C:\Users\guddi\OneDrive\Desktop\cctech_progress\week7\day4\OpenGlShape\Socket cap screw.stl"
    std::vector<float> points;
    std::ifstream fin("C:/Users/guddi/OneDrive/Desktop/cctech_progress/week7/day4/OpenGlShape/Socket cap screw.stl", std::ios::binary);
    if (!fin) {
        qDebug() << "file is not open....";
        return points;
    }
    //std::string s;
    //fin.read((char*)&s, sizeof(s));
    //qDebug() << s;
    ;
    //fin.read((char*)&s, 80);
    char h[80];
    fin.read(h, 80);

    //for (char c : h) {
    //        qDebug()<< float(c);
    //}
    //while (fin) {
    //    char c;
    //    fin.get(c);
    //    qDebug()<< float(c);
    //}

    int cnt;
    fin.read((char*)&cnt, 4);
    qDebug() << "number of triangle"<<cnt;
    for (int i = 0;i < cnt;i++) {
        float normal[3];
        float v1[3];
        float v2[3];
        float v3[3];
        char atr[2];
        fin.read((char*)&normal, 12);
        fin.read((char*)&v1, 12);
        fin.read((char*)&v2, 12);
        fin.read((char*)&v3, 12);
        fin.read(atr, 2);
        addData(v1, points);
        addData(v2,points);
        addData(v3, points);
    }
    //for (int i = 0;i < points.size();i++) {
    //    qDebug() << points[i];
    //}
    qDebug() << "file open sucessful";
    return points;
}

void STL_Binary::addData(float v[], std::vector<float> &points)
{

    for (int i = 0;i < 3;i++) {
        points.push_back(v[i]*0.3f);
    }
    points.push_back(0);
    points.push_back(1);
    points.push_back(0);
}
