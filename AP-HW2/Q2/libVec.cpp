#include "libVec.h"
#include <iostream>
#include <vector>

long int libVec::counter(int n){
	std::vector<int> v;
	long int s{};
	for (int i = 1; i <= n; ++i)
	{
		v.push_back(i);
		s+=v[i-1];
	}
	return s;
}