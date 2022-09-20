#ifndef POINT_H
#define POINT_H


#include <iostream>

class Point
{
public:
	 Point(double xx,double yy,double zz):x{xx},y{yy},z{zz}{}
	 Point(double xx,double yy):x{xx},y{yy}{}

	 void show_2D(){std::cout<<x<<" , "<<y<<std::endl;}
	 void show_3D(){std::cout<<x<<" , "<<y<<" , "<<z<<std::endl;}
	
//private:
	double x;
	double y;
	double z;

	
};

#endif