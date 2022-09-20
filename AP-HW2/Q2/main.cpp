#include <iostream>
#include <vector>
#include <chrono>
#include "libArr.h"
#include "libVec.h"
#include <iomanip>
using namespace std::chrono;
template <typename T1,typename T2>
double runTime(T1,T2,int n);

int main(){

	int n{1};
    //object of libArr
    libArr object_arr;
    long int (libArr::*ptfptr_Arr)(int)=&libArr::counter;
     
    //object of libVec
    libVec object_vec;
    long int (libVec::*ptfptr_Vec)(int)=&libVec::counter;
    
    while(n<=1000000){

                                                                                              
        std::cout << "Time taken by libVec for(n = "<<std::setw(7)<<n<<"):"<<std::setw(10)<<runTime(object_vec,ptfptr_Vec,n) << "  milliseconds"<<std::endl;
        
        std::cout << "Time taken by libArr for(n = "<<std::setw(7)<<n<<"):"<<std::setw(10) <<runTime(object_arr,ptfptr_Arr,n) << "  milliseconds"<<std::endl;
        std::cout<<std::endl;
       
    	n=n*10;
    }

	return 0;
}

template <typename T1,typename T2>
double runTime(T1 object,T2 ptfptr,int n){
    //claculate time by hight resulotion
    auto start = high_resolution_clock::now();

    std::cout<<"Sum = " <<(object.*ptfptr)(n) <<std::endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast< nanoseconds>(stop - start);
    //to calculate time on miliseconds
    return duration.count()/1000000.0;   

}

