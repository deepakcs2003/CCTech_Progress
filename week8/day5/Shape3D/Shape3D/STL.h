#pragma once
#include <vector>
#include <QString>

class STL
{
public:
    STL();
    ~STL();

    std::vector<float> loadSTL();          
    void saveSTL(const std::vector<float>& points); 

private:
    float genCol();
};