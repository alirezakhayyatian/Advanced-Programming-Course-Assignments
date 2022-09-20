#include "stack.h"
//#include "ctext.h"
#include <iostream>

template<class T>
void Stack<T>::push(T cText_ptr){

	v.push_back(cText_ptr);

}

template<class T>
T Stack<T>::pop(){
	T temp =v[v.size()-1];
	v.pop_back();
	return temp;
}



