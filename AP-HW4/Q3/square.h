#ifndef SQUARE_H
#define SQUARE_H

#include "twodimensionshape .h"
#include <iostream>

class Square:public Twodimensionshape
{
public:

    double ox;
	double oy;
	double length;
	

	Square(double len,double x,double y):Twodimensionshape{}{
		length=len;
		ox=x;
		oy=y;
	}
    Square(double len,double x):Square(len,x,0){}
    Square(double len):Square(len,0,0){}

    virtual double area()const{return length*length;}

	virtual void print()const{
    std::cout<<"Square side length = "<<length<<"\n"<<"center->("<<ox<<","<<oy<<")"<<"\n"<<"area of "<<area()<<std::endl;
    }

    virtual void operator+(Point p){
    	ox=ox+p.x;
    	oy=oy+p.y;
    };
	
};

#endif