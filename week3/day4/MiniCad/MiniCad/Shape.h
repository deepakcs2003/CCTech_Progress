#pragma once
#include <string>
class Shape
{
protected:
	int id;
public:

	Shape(int id);
	virtual void move(double dx, double dy);
	virtual void scale (double factor);
    virtual std::string getType() const = 0;
	virtual void display() const;
	int getId() const;
	virtual ~Shape();
};

