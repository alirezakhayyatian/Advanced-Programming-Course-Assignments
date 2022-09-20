#include <iostream>
#include <array>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <set>


void myfuction(int a){std::cout<< a<< " ";}
void func(std::set<int>& z,size_t size);

struct randGen{
	randGen(int l,int h):low(l),high(h){};

	int operator()()const{
		return low +(rand()%(high-low+1));
	}
private:
	int low;
	int high;

};

int asd(int low,int high){return low +(rand()%(high-low+1));}

int ran_func();

int main(){
    srand(static_cast<unsigned int> (clock()) );
    int arr[50]{1,2,3};
    //vector a 
    std::cout<<"vector a"<<std::endl;
    std::vector<int>a(arr,arr+50);
    std::for_each(begin(a),end(a),myfuction);
    std::cout<<"\n"<<std::endl;

    //vector b whith random number
    std::vector<int>b(50);
    std::cout<<"vector b with random value"<<std::endl;
   
    std::generate(b.begin(),b.end(),randGen(1,50));
    std::for_each(begin(b),end(b),myfuction);
    std::cout<<"\n"<<std::endl;
    

    //erase duplicate value of vector b
    std::sort(begin(b),end(b));
    auto last = std::unique(begin(b),end(b) ) ;
    b.erase(last,end(b));
    std::cout<<"vector b after erase"<<std::endl;

    std::for_each(begin(b),end(b),myfuction);
    std::cout<<"\n"<<std::endl;
    

    //vector c without using recursive function

    std::vector<int> c(50);    
    std::iota(begin(c),end(c),0);

    std::random_device rd ;
    std::mt19937 g(rd());
    std::shuffle(begin(c),end(c),g);

    std::cout<<"Set c without using recursive function"<<std::endl;
    std::for_each(begin(c),end(c),myfuction);
    std::cout<<"\n"<<std::endl;
    


    
    //vector c using recursive function
    std::set<int> c1;
    func(c1,50);

    std::cout<<"Set c using recursive function"<<std::endl;
    std::for_each(begin(c1),end(c1),myfuction);
    std::cout<<"\n"<<std::endl;
    


    //find diffrence between squre of b & c 
    int sq1=std::inner_product(begin(b),end(b),begin(b),0);
    int sq2=std::inner_product(begin(c),end(c),begin(c),0);

    std::cout<<"diffrence between squre of b & c is:"<< sq1-sq2<<std::endl;
    
    
	return 0;
}

void func(std::set<int>& z,size_t size){
    z.insert(asd(1,500));
	if(z.size() < size)
	func(z,50);
}

















