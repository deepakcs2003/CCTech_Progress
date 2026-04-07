#include "STL.h"
#include <fstream>
#include <sstream>
#include <QFileDialog>
#include <QDebug>

STL::STL() {}
STL::~STL() {}

//load stl file 
std::vector<float> STL::loadSTL()
{
    std::vector<float> points;

    //Open file dialog
    QString filePath = QFileDialog::getOpenFileName(
        nullptr,
        "Open STL File",
        "",
        "STL Files (*.stl)"
    );

    if (filePath.isEmpty()) {
        qDebug() << "No file selected";
        return points;
    }

    std::ifstream fin(filePath.toStdString());
    if (!fin) {
        qDebug() << "Can't open file";
        return points;
    }

    std::string line;
    while (std::getline(fin, line)) {
        std::stringstream ss(line);
        std::string word;
        std::vector<std::string> str;

        while (ss >> word) {
            str.push_back(word);
        }

        if (str.empty()) continue;

        if (str[0] == "vertex") {
            float v1 = std::stof(str[1]);
            float v2 = std::stof(str[2]);
            float v3 = std::stof(str[3]);

            points.push_back(v1);
            points.push_back(v2);
            points.push_back(v3);

            //// default color (red)
            //points.push_back(1);
            //points.push_back(0);
            //points.push_back(0);
        }
    }

    return points;
}

// funtion to save slt file
void STL::saveSTL(const std::vector<float>& points)
{
    //  Save file dialog
    QString filePath = QFileDialog::getSaveFileName(
        nullptr,
        "Save STL File",
        "",
        "STL Files (*.stl)"
    );

    if (filePath.isEmpty()) {
        qDebug() << "Save cancelled";
        return;
    }

    std::ofstream fout(filePath.toStdString());
    if (!fout) {
        qDebug() << "Can't create file";
        return;
    }

    fout << "solid model\n";

    for (size_t i = 0; i < points.size(); i += 18)
    {
        fout << "  facet normal 0 0 0\n";
        fout << "    outer loop\n";

        for (int j = 0; j < 3; j++) {
            float x = points[i + j * 6 + 0];
            float y = points[i + j * 6 + 1];
            float z = points[i + j * 6 + 2];

            fout << "      vertex "
                << x << " " << y << " " << z << "\n";
        }

        fout << "    endloop\n";
        fout << "  endfacet\n";
    }

    fout << "endsolid model\n";

}

float STL::genCol()
{
    return (rand() % 101) / 100.0f;
}