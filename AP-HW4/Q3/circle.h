#ifndef CIRCLE_H
#define CIRCLE_H

#include "twodimensionshape .h"
#include <iostream>



class Circle:public Twodimensionshape
{
public:

    double ox;
	double oy;
	double r;
	

	Circle(double radius,double x,double y):Twodimensionshape{}{
		r=radius;
		ox=x;
		oy=y;
	}
	Circle(double radius,double x):Circle(radius,x,0){};
	Circle(double radius):Circle(radius,0,0){};

    virtual double area()const{return 3.1415*r*r;}

    virtual void print()const{
    std::cout<<"Circle radius = "<<r<<"\n"<<"center->("<<ox<<","<<oy<<")"<<"\n"<<"area of "<<area()<<std::endl;

    }

    virtual void operator+(Point p){
    	ox=ox+p.x;
    	oy=oy+p.y;
    };

};

#endif