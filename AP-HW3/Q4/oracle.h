#ifndef ORACLE_H
#define ORACLE_H
#include <iostream>
#include <string>

#include "human.h"


class Oracle;
void Base(int decimal,int transformer[]);
void Base_numberOfChildren (int decimal,int base,int transformer[]);


class Oracle{
public:
	Oracle(std::string Name);
	bool marry(Human*,Human*);
    void setChild(Human*,Human*,Human*);
    bool isFamily(Human*,Human*);
    Human** getFamily(Human*);
    int getPopulationOfFamily(Human*);



private:
	std::string Name;
};









#endif