#include "maxheap.h"
#include  <cmath>

Maxheap::Maxheap(int cap) 
{ 
    heap_size = 0; 
    capacity = cap; 
    harr = new int[cap]; 
}
//Defaule Constructor 
Maxheap::Maxheap():Maxheap(10){ 
    std::cout<<"Defaule Constructor"<<std::endl;
}
//Copy Constructor 
Maxheap::Maxheap(const Maxheap& h){
	std::cout<<"Copy Constructor"<<std::endl;
	heap_size=h.heap_size;
	capacity=h.capacity;
	harr=new int[capacity];
	for (int i = 0; i < heap_size; ++i)
	{
		harr[i]=h.harr[i];
		

	}
	
}

Maxheap::Maxheap(int* arr,int num){
	heap_size=num;
	capacity=num;
	harr=new int[capacity];
	int i{};
	for (int j = 0; j < heap_size; ++j)
	{
		harr[j]=arr[j];
		i=j;
		 while (i != 0 && harr[Parent(i)] < harr[i]) 
        { 
         swap(&harr[i], &harr[Parent(i)]); 
         i = Parent(i); 
        }
		
	}

	
}
  
// add a new key 'k' 
void Maxheap::add(int k) 
{ 
	capacity++;
    if (heap_size == capacity) 
    { 
        std::cout << "\nOverflow: Could not insertKey\n"; 
        return; 
    } 
  
    // First insert the new key at the end 
    heap_size++; 
    int i = heap_size - 1; 
    harr[i] = k; 
  
    // Fix the min heap property if it is violated 
    while (i != 0 && harr[Parent(i)] < harr[i]) 
    { 
       swap(&harr[i], &harr[Parent(i)]); 
       i = Parent(i); 
    } 
} 
  
// Decreases value of key at index 'i' to new_val.  It is assumed that 
// new_val is smaller than harr[i]. 
void Maxheap::decreaseKey(int i, int new_val) 
{ 
    harr[i] = new_val; 
    while (i != 0 && harr[Parent(i)] > harr[i]) 
    { 
       swap(&harr[i], &harr[Parent(i)]); 
       i = Parent(i); 
    } 
} 
  
// Method to remove maximum element (or root) from min heap 
int Maxheap::extractMax() 
{ 
    if (heap_size <= 0) 
        return INT_MIN; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return harr[0]; 
    } 
  
    // Store the maximum value, and remove it from heap 
    int root = harr[0]; 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    Maxheapify(0); 
  
    return root; 
} 
  
  
// This function deletes key at index i. It first reduced value to minus 
// infinite, then calls extractMin() 
void Maxheap::Delete() 
{ 
    //decreaseKey(0, INT_MAX); 
    //extractMax(); 
    if (heap_size <= 0) 
        return; 
    if (heap_size == 1) 
    { 
        heap_size--; 
        return; 
    } 
  
    //remove maximuu from heap 
    harr[0] = harr[heap_size-1]; 
    heap_size--; 
    Maxheapify(0); 
}


  
// A recursive method to heapify a subtree with the root at given index 
// This method assumes that the subtrees are already heapified 
void Maxheap::Maxheapify(int i) 
{ 
	//std::cout<<"Heapify"<<std::endl;
    int l = left(i); 
    int r = right(i); 
    int smallest = i; 
    if (l < heap_size && harr[l] > harr[i]) 
        smallest = l; 
    if (r < heap_size && harr[r] > harr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        swap(&harr[i], &harr[smallest]); 
        Maxheapify(smallest); 
    } 
} 

// A utility function to swap two elements 
void swap(int *x, int *y) 
{ 
    int temp = *x; 
    *x = *y; 
    *y = temp; 
} 

std::ostream& operator<<(std::ostream& os,const Maxheap& h){
	int a{};
	int b{};
	for (int i = 0; i < h.heap_size; ++i)
	{ 
		a++;
		os<<h.harr[i]<<" ";
		b=std::log(a+1) / std::log(2);
		if(b == ( std::ceil( std::log(a+1)/std::log(2) )))
			if(a !=(h.heap_size))
				std::cout<<std::endl;

	}
	
	return os;
}

int Maxheap::getHeight(){
   return (std::ceil(std::log(heap_size+1)/log(2))-1);
}

void Maxheap::printArray(){
	for (int i = 0; i < heap_size; ++i)
	{
		std::cout<<harr[i]<<" ";
	}
	std::cout<<std::endl;
}


void Maxheap::Heapsort(){
	int* arr_new=new int[heap_size];
	int temp= heap_size;
	for (int i = 0; i < temp; ++i)
	{
		arr_new[i]=extractMax();
		
	}
	harr=arr_new;
	arr_new=nullptr;
	heap_size=temp;
	this->printArray();
}





int Maxheap::operator+(int a){
	return 1;

}
int Maxheap::operator-(int a){
	return 1;

}



