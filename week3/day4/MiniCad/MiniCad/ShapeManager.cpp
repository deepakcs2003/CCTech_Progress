#include "ShapeManager.h"
#include <map>
#include "Shape.h"
#include <memory>
#include <stdexcept>
#include <iostream>
using namespace std;


void ShapeManager::addObject(unique_ptr<Shape> obj)
{
	int id = obj->getId();
    object.emplace(id, std::move(obj));

}

void ShapeManager::deleteObject(int id)
{
	if (object.erase(id) == 0) {
		throw runtime_error("invalid id");
	}
}

Shape* ShapeManager::findObject(int id) const
{
	auto it=object.find(id);
	if (it!=object.end()){
		return it->second.get();
	}
	return nullptr;
}

void ShapeManager::displayAll() const
{
	for (const auto& pair : object) {
		cout << "ID: " << pair.first << "\n";
		pair.second->display();
	}
}

void ShapeManager::moveObject(int id, double dx, double dy)
{
	auto obj = findObject(id);
	if (!obj)
		throw std::runtime_error("Invalid ID");

	obj->move(dx, dy);
}

void ShapeManager::scaleObject(int id, double factor)
{
	if (factor <= 0)
		throw std::invalid_argument("Scaling factor must be positive");

	auto obj = findObject(id);
	if (!obj)
		throw std::runtime_error("Invalid ID");

	obj->scale(factor);
}
