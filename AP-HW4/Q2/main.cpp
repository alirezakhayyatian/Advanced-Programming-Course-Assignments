#include <iostream>
#include <vector>
#include <string>
#include <memory>	
template<typename T>
void display(const std::vector<T>);

template<typename T>
void printSize(const std::vector<T>& v);

std::string num(int);

int main(){
	std::vector<std::unique_ptr<std::string> >v;
	for (int i = 0; i < 1000; ++i)
	{
		
		std::unique_ptr<std::string> ptr{new std::string {"Str"+num(i)} };
		v.push_back(std::move(ptr));
		printSize(v);

		
	}
    std::vector<std::unique_ptr<std::string> >v2;
    v2.reserve(1000);
    for (int i = 0; i < 1000; ++i)
	{
		
		std::unique_ptr<std::string> ptr{new std::string {"Str"+num(i)} };
		v2.push_back(std::move(ptr));
		printSize(v);
		
	}
	for (int i = 0; i < 1000; ++i)
		std::cout<<*v[i]<<std::endl;

	return 0;
}


template<typename T>
void printSize(const std::vector<T>& v){
    std::cout<<v.size()<<"  "<<v.capacity()<<std::endl;

}

std::string num(int i){
    std::string s;
	if(i<10)
		s="00"+std::to_string(i);
	else if(i<100 && i>=10)
		s="0"+std::to_string(i);
    else
		s=std::to_string(i);
	return s;

}
