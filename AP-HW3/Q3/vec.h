#ifndef VEC_H
#define VEC_H
#include <iostream>

class Vec;
int dot(const Vec& v1,const Vec& v2);


class Vec{
public:
	//constructors
	Vec();
	//copy constructor
	Vec(const Vec&);
	//move constructor
	Vec(Vec&&);
	~Vec();

	void push_back(int);
    void pop_back();
    void show();
    int dot(const Vec&,const Vec&);
    Vec cross(const Vec& v1,const Vec& v2);

    Vec& operator=(const Vec& v);


    bool operator<(const Vec&)const;
    bool operator==(const Vec&)const;

    void operator*(const Vec&)const;



	int capacity;	
	int size;	
	int* arr;
private:
	int capacity_middle;
	int Len;

};


#endif