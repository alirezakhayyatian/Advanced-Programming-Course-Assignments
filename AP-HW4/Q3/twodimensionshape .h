#ifndef TWODIMENSIONSHAPE
#define TWODIMENSIONSHAPE

#include "shape.h"
#include <iostream>

class Twodimensionshape:public Shape 
{
public:
	Twodimensionshape():Shape{}{}
	virtual void print()const{};
    virtual double area()const{return 0;}
    virtual double volume()const{return 0;}
	
    virtual void operator+(Point p){};
};

#endif
