#include"maxheap.h"
#include <iostream>

int main()
{
	Maxheap h1{};
	h1.add(25);
	h1.add(32);
	h1.add(17);
	h1.add(23);
	h1.add(101);  
 
	std::cout << h1 << std::endl;  
	/* 
	101,
	32, 17,
	23, 25
	*/
	std::cout << h1.parent(2) << std::endl; // 101                
	std::cout << h1.LeftChild(0) << std::endl;  // 32
	std::cout << h1.RightChild(0) << std::endl;  // 17


	int arr[7] {23, 1, 7, 52, 11, 10, 75};
	Maxheap h2{arr, 7};
	//h2.add(14);
			
	std::cout << h2 << std::endl;  
	std::cout << h2.getHeight() << std::endl; // 2


	Maxheap h3{h2};

	h2.Heapsort();
	h2.printArray(); // 75, 52, 23, 11, 10, 7, 1

	
	std::cout << h3.max(); //75

	h3[0] = h3[0] - 25;                                      //////22222 

	std::cout << h3.max(); //52
	h3.Delete();                                              
	std::cout << h3.max(); //50


		
	return 0;
}