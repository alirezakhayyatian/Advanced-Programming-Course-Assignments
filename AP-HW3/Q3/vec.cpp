#include "vec.h"
#include <cmath>
//constructors
//Default Constructor
Vec::Vec(){
	std::cout<<"Default Constructor"<<std::endl;
	size=0;
	capacity=0;
	capacity_middle=0;
	Len=0;
	arr=nullptr;
	
}
//Copy Constructor
Vec::Vec(const Vec& vec){
	std::cout<<"Copy Constructor "<<std::endl;
	size=vec.size;
	capacity=vec.capacity;
	capacity_middle=vec.capacity_middle;
	Len=vec.Len;
	arr=new int [capacity];
	for (int i = 0; i < size; ++i){
		arr[i]=vec.arr[i];
	}
}
//Move Constructor
Vec::Vec(Vec&& vec){
	std::cout<<"Move Constructor"<<std::endl;
	size=vec.size;
	capacity=vec.capacity;
	capacity_middle=vec.capacity_middle;
	Len=vec.Len;

	arr=vec.arr;
    vec.arr=nullptr;
}

//destructor
Vec::~Vec(){
	delete[] arr;
}
//to insert new elemnt to end of vector
void Vec::push_back(int num){
	
	size++;
	//calculat capacity 
	//ceil calculate bracket of double
    Len=std::ceil( std::log(size)/std::log(2) );
    capacity_middle=std::pow(2,Len);

    if(  ! (capacity == capacity_middle) ){
    	
        //std::cout<<capacity<<std::endl;
        capacity=capacity_middle;
        int* arr_new=new int[capacity];
        for (int i = 0; i < (size-1);++i)
        {
    	    arr_new[i]=arr[i];
        }
        arr_new[(size-1)]=num;
        delete[] arr;
        arr=arr_new;
        arr_new=nullptr;
        //std::cout<<"arr_new created"<<std::endl;
        
    }
    else{
    	arr[(size-1)]=num;
    	//std::cout<<"else"<<std::endl;
    }
}
//delede elemnt from end of vector
void Vec::pop_back(){
	//int* arr_new=new int
	size--;
	Len=std::ceil( std::log(size)/std::log(2) );
	capacity=std::pow(2,Len);
	//capacity_middle=std::pow(2,Len);
	/*if( ! (capacity == capacity_middle) ){ 
        capacity=capacity_middle; 
	}*/
    //product new arr whith new capacity
	int* arr_new=new int[capacity];
	for (int i = 0; i < size; ++i)
	{
		arr_new[i]=arr[i];
	}
	delete[] arr;
	arr=arr_new;
	arr_new=nullptr;

}
//showing array of vector
void Vec::show(){
	std::cout<<"{ ";
	for (int i = 0; i < size; ++i)
	{
		std::cout<<arr[i]<<" ";
	}
	std::cout<<"}"<<std::endl;
}

//calculate internal product of to vector
int dot(const Vec& v1,const Vec& v2){
	if(!(v1.size == v2.size)){
		std::cout<<"size of vector is not equall"<<std::endl;
		return 0;
	}
	int sum{};
	for (int i = 0; i < v1.size; ++i)
	{
		sum += (v1.arr[i]) * (v2.arr[i]);
	}
	std::cout<<"internal mix is:"<<sum<<std::endl;
	return sum;
}

//calculate cross product of two vector whith size = 3
//and return vector
Vec Vec::cross(const Vec& v1,const Vec& v2){
	if( !( (v1.size==3) && (v2.size==3) ) ){
		std::cout<<" crossprduct size of both of vector should be 3"<<std::endl;
		return *this;
	}
    delete[] arr;
    arr= new int[3];
	arr[0] = v1.arr[1]*v2.arr[2] - v1.arr[2]*v2.arr[1];
    arr[1] = v1.arr[2]*v2.arr[0] - v1.arr[0]*v2.arr[2];
    arr[2] = v1.arr[0]*v2.arr[1] - v1.arr[1]*v2.arr[0];
    std::cout<<"Cross product is: { "<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" }"<<std::endl;
    return *this;
}
//it is needed because class harr dynamic array
Vec& Vec::operator=(const Vec& vec){

    std::cout<<"operator = copy version"<<std::endl;
	size=vec.size;
	capacity=vec.capacity;
	capacity_middle=vec.capacity_middle;
	Len=vec.Len;

	delete[] arr;
	arr=new int [capacity];
	for (int i = 0; i < size; ++i){
		arr[i]=vec.arr[i];
	}
    
    return *this;
}



//operator < & == is enough to every complex
// of <=>
bool Vec::operator<(const Vec& vec)const{
	if(size < vec.size)
		return 1;
	else 
		return 0;
}

bool Vec::operator==(const Vec& vec)const{
	if(size == vec.size)
		return 1;
	else 
		return 0;
}

//calculate cross product of two vector whith size = 3
//and only print arr of output
void Vec::operator*(const Vec& v2)const{
	if( !( (size==3) && (v2.size==3) ) ){
		std::cout<<" crossprduct size of both of vector should be 3"<<std::endl;
		
	}
	int* arr1=new int[3];
	arr1[0] = arr[1]*v2.arr[2] - arr[2]*v2.arr[1];
    arr1[1] = arr[2]*v2.arr[0] - arr[0]*v2.arr[2];
    arr1[2] = arr[0]*v2.arr[1] - arr[1]*v2.arr[0];
    std::cout<<"Cross product is: { "<<arr1[0]<<" "<<arr1[1]<<" "<<arr1[2]<<" }"<<std::endl;

	
}



/*Vec::Vec(const Vec& arr1){
	Len=0;
	while(arr1[Len++]);
	arr=new int[Len];
	for (int i = 0; i < Len; ++i)
	{
		arr[i]=arr1[i];
	}
}*/