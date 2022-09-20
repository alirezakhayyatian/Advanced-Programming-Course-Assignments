#ifndef CUBE_H
#define CUBE_H

#include "threedimensionshape.h"
#include <iostream>

class Cube:public Threedimensionshape
{                    
public:

    double ox;
	double oy;
	double oz;
	double l;
	

	Cube(double length,double x,double y,double z):Threedimensionshape{}{
		l=length;
		ox=x;
		oy=y;
		oz=z;
	}
	Cube(double length,double x,double y):Cube(length,x,y,0){}
	Cube(double length,double x):Cube(length,x,0,0){}
	Cube(double length):Cube(length,0,0,0){}

    virtual double area()const{return 6*l*l;}
    virtual double volume()const{return l*l*l;}

	virtual void print()const{
    std::cout<<"Cube side length = "<<l<<"\n"<<"center->("<<ox<<","<<oy<<","<<oz<<")"<<"\n"<<"area of "<<area()<<"& volume of "<<volume() <<std::endl;
    }

    virtual void operator+(Point p){
    	ox=ox+p.x;
    	oy=oy+p.y;
    	oz=oz+p.z;
    };
	
};

#endif