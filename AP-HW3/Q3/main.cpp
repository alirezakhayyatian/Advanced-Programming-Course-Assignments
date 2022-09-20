#include <iostream>
#include "vec.h"
#include <utility>

using namespace std::rel_ops;

int main(){
     //default constructor	    
     Vec v1;
     //push_back function to 
     //insert elemnt to end of vector
     v1.push_back(8);
     v1.push_back(74);
     v1.push_back(52);
     v1.push_back(14);
     std::cout<<"capacity of vector before addind fivth elemnt is:"<<v1.capacity<<std::endl;
     v1.push_back(95);
     std::cout<<"capacity of vector after addind fivth elemnt is:"<<v1.capacity<<std::endl;
     v1.push_back(10);
     v1.push_back(111);
     v1.push_back(20);
     v1.push_back(30);
     v1.push_back(50);

     std::cout<<v1.arr[3]<<std::endl;
     std::cout<<v1.arr[9]<<std::endl;
     //pop_back function to 
     //delete elemnt to end of vector
     v1.pop_back();
     v1.push_back(64);
     std::cout<<v1.arr[9]<<std::endl;
     v1.show();
    std::cout<<"size of vector v1 is:"<<v1.size<<"capacity of vector v1 is:"<<v1.capacity<<std::endl;
    
    Vec a;
     a.push_back(1);
     a.push_back(4);
     a.push_back(5);

    Vec b;
     b.push_back(2);
     b.push_back(3);
     b.push_back(1);

    //internal product 
    dot(a,b);
    //copy constructor
    Vec c{a};
    //show function
    c.show();
    //after upper line we dont access to arr of b
    //move constructor
    Vec V_rvalue{std::move(b)};
    V_rvalue.show();

    if(v1 >= a)
    std::cout<<"a is smaller size than reza"<<std::endl;
    
    
    //to find cross product  
    Vec z{};
    //cross product function
    Vec d;
    d.push_back(2);
    d.push_back(5);
    d.push_back(3);
    z.cross(a,d);
    //print cross product with operator*
    a * d;


	return 0;
}










