#include <iostream>
#include <vector>
#include <algorithm>
//two initialize vec1
int func() {
	static int n = 0;
	n++;
	return n;
}
//two initialize vec2
int func1() {
	static int n = 0;
	n++;
	return n;
}
//to print 
void myfuction(int a) { std::cout << a << " "; }

int main() {
	//part A
	std::vector<int> vec1(100);
	std::generate(vec1.begin(), vec1.end(), func );
	std::cout << "vec1 is:" << "\n";
	std::for_each(begin(vec1), end(vec1), myfuction);
	std::cout <<"\n" <<std::endl;

	std::vector<int> vec2(10);
	std::generate(vec2.begin(), vec2.end(), func1);
	std::cout << "vec2 is:" << "\n";
	std::for_each(begin(vec2), end(vec2), myfuction);	
	std::cout << "\n" << std::endl;
	//part B
	std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
	std::cout << "Part B" << "\n";
	std::for_each(begin(vec2), end(vec2), myfuction);
	std::cout << "\n" << std::endl;

	//part C
	std::vector<int> odd_vec(50);
	std::copy_if(vec1.begin(), vec1.end(), odd_vec.begin(), [](int i) {return i % 2 != 0; });
	std::cout << "Odd_vec is:" << "\n";
	std::for_each(begin(odd_vec), end(odd_vec), myfuction);
	std::cout << "\n" << std::endl;

	//part D
	std::vector<int> reverse_vec(vec1.rbegin(),vec1.rend());
	std::cout << "Reverse vector:" << "\n";

	std::for_each(begin(reverse_vec), end(reverse_vec), myfuction);
	std::cout << "\n" << std::endl;
	//part D
	//save vec2 to parallel sorting
	std::vector<int> temp_vec(110);
	std::copy(begin(vec2), end(vec2), begin(temp_vec));
	std::cout << "Normal Sort:" << "\n";

	std::sort(begin(vec2), end(vec2));
	std::for_each(begin(vec2), end(vec2), myfuction);
	std::cout << "\n" << std::endl;
	
	//std::sort(std::execution::par_unseq, temp_vec.begin(), temp_vec.end());
}
