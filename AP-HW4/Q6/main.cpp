#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>

void myfuction(int a){std::cout<< a<< " ";}
int mix(int a){return a*2;}
bool removeSet(int& a){return a>3;}
int main(){
    //part 0
	std::vector<int> vec{1,2,3,4,5,4,3,2,1};
    std::cout<<"first vector whithout any method is"<<"\n";
    std::for_each(begin(vec),end(vec),myfuction);
    std::cout<<"\n";
    
    //part 1
    std::cout<<"after remove"<<"\n";
	auto remove = std::remove(begin(vec),end(vec),2);
    std::for_each(begin(vec),remove,myfuction);
    std::cout<<"\n";
    //part 2
    std::cout<<"after times two"<<"\n";
    std::transform(begin(vec),end(vec),begin(vec),mix);
    std::for_each(begin(vec),end(vec),myfuction);
    std::cout<<std::endl;

    //part3
    std::cout<<"sort by distance from average"<<"\n";
    double avg = std::accumulate(begin(vec),end(vec),0.0)/vec.size() ;
    std::sort(begin(vec),end(vec),[avg](const int a, const int b){return std::abs(a-avg)>std::abs(b-avg); });
    std::for_each(begin(vec),end(vec),myfuction);
    std::cout<<std::endl;

    //part4
    std::cout<<"after remove duplicate value of vector"<<"\n";
    //std::sort(begin(vec),end(vec));
    auto last = std::unique(begin(vec),end(vec) ) ;
    vec.erase(last,end(vec));
    std::for_each(begin(vec),end(vec),myfuction);
    std::cout<<"\n";
    
    //part5 A
    std::cout<<"copy vetor to set"<<"\n";
    std::set<int> s;
    std::set<int>::iterator itr = s.begin();
    std::copy(begin(vec),end(vec),inserter(s,itr));
    std::for_each(begin(s),end(s),myfuction);
    std::cout<<"\n";
    
    //part5 B
    std::cout<<"after remove by bound 3"<<"\n";
    std::sort(begin(vec),end(vec));

    std::vector<int> temp(begin(s),end(s));
    s.erase(begin(s),end(s));

    temp.erase(std::remove_if(begin(temp),end(temp),removeSet),end(temp));

    std::set<int>::iterator itr1 = s.begin();
    std::copy(begin(temp),end(temp),inserter(s,itr1));
    std::for_each(begin(s),end(s),myfuction);
    std::cout<<"\n";

    

	return 0;


}

