#ifndef SPHERE_H
#define SPHERE_H

#include "threedimensionshape.h"
#include <iostream>

class Sphere:public Threedimensionshape
{                    
public:

    double ox;
	double oy;
	double oz;
	double r;
	

	Sphere(double raduis,double x,double y,double z):Threedimensionshape{}{
		r=raduis;
		ox=x;
		oy=y;
		oz=z;
	}
	Sphere(double raduis,double x,double y):Sphere(raduis,x,y,0){}
	Sphere(double raduis,double x):Sphere(raduis,x,0,0){}
	Sphere(double raduis):Sphere(raduis,0,0,0){}

    virtual double area()const{return 3.1415*4*r*r;}
    virtual double volume()const{return 3.1415*4*r*r*r/3;}

	virtual void print()const{
    std::cout<<"Sphere raduis = "<<r<<"\n"<<"center->("<<ox<<","<<oy<<","<<oz<<")"<<"\n"<<"area of "<<area()<<"& volume of "<<volume() <<std::endl;
    }

    virtual void operator+(Point p){
    	ox=ox+p.x;
    	oy=oy+p.y;
    	oz=oz+p.z;
    };
	

	
};

#endif