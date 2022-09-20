#include <iostream>
#include <vector>
//#include "ctext.h"
template<class T>
class Stack{

private:

	std::vector<T> v;
	
public:

    Stack()=default;
	//Stack(const Stack& stack);
	T pop();
	void push(T);
    //void display();

    int getCount(){return v.size();}
    bool isEmpty(){return v.size()==0;}



};