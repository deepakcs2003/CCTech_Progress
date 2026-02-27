#pragma once
#include <map>
#include "Shape.h"
#include <memory>

class ShapeManager
{
private:
    std::map<int, std::unique_ptr<Shape>> object;
public:
    void addObject(std::unique_ptr<Shape> obj);
    void deleteObject(int id);
    Shape* findObject(int id) const;
    void displayAll() const;
    void moveObject(int id, double dx, double dy);
    void scaleObject(int id, double factor);
};
