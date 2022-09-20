#include "libArr.h"
#include <iostream>

//double runTime(double(*f)(double));

long int libArr::counter(int n){
	int arr[n];
	long int s{};
	for (int i = 1; i <= n; ++i)
	{
		arr[i-1]=i;
		s+=arr[i-1];
	}
	return s;
	
}



