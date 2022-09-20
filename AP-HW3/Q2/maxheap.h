#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <climits>
#include <vector>

class Maxheap;
std::ostream& operator<<(std::ostream& os,const Maxheap& h);


void swap(int *x, int *y); 

class Maxheap 
{ 
   /* int *harr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of max heap 
    int heap_size; // Current number of elements in max heap*/ 
public:
    
    int *harr; // pointer to array of elements in heap 
    int capacity; // maximum possible size of max heap 
    int heap_size; // Current number of elements in max heap 

    // Constructor 
    Maxheap(int capacity); 
    Maxheap();
    Maxheap(const Maxheap& ); 
    Maxheap(int*,int num);
  
    // to heapify a subtree with the root at given index 
    void Maxheapify(int ); 
    int parent(int i){return harr[(i-1)/2];} //small 
    int Parent(int i) { return (i-1)/2; }    //capital
  
    // to get index of left child of node at index i 
    int LeftChild(int i){ return  harr[(2*(i) + 1)];}
    int left(int i) { return (2*i + 1); } 
  
    // to get index of right child of node at index i 
    int RightChild(int i){ return  harr[(2*(i) + 2)];}
    int right(int i) { return (2*i + 2); } 
  
    // to extract the root which is the minimum element 
    int extractMax(); 
  
    // Decreases key value of key at index i to new_val 
    void decreaseKey(int i, int new_val); 
  
    // Returns the minimum key (key at root) from min heap 
    int getMax() { return harr[0]; } 
  
    // Deletes a key stored at index i 
    void Delete(); 
    //int Delete();
  
    // add a new key 'k' 
    void add(int k); 
    int getHeight();
    void printArray();
    int max(){return harr[0];}
    void Heapsort();

    //operator
    int& operator[](const int& i){return harr[i]; }
    int operator+(int);
    int operator-(int);





};

#endif