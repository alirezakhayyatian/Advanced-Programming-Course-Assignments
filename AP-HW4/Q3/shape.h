#ifndef Shape_H
#define Shape_H

#include <iostream>
#include "point.h"


class Shape
{
public:
	Shape(){}
    virtual void print()const=0;
    virtual double area()const=0;
    virtual double volume()const=0;
    virtual void operator+(Point p)=0;
	friend std::ostream& operator<<(std::ostream& os,const Shape& shape){
		shape.print();
		return os;
	}
};


#endif
