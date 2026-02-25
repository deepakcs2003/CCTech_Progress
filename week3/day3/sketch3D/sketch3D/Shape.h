#pragma once
#include <iostream>
#include <string>
using namespace std;
class shape
{
protected:
    string name;
public:
    shape(string name);
    virtual void display()=0;
    virtual double area()=0;
    virtual ~shape();
};

