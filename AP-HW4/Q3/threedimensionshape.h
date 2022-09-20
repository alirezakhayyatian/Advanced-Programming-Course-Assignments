#ifndef THREEDIMENSIONSHAPE
#define THREEDIMENSIONSHAPE

#include "shape.h"
#include <iostream>

class Threedimensionshape:public Shape 
{
public:
	Threedimensionshape():Shape{}{}
	virtual void print()const{};
    virtual double area()const{return 0;}
    virtual double volume()const{return 0;}

    virtual void operator+(Point p){};
};

#endif
