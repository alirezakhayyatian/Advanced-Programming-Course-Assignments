#include <iostream>
#include <string>
#include <fstream>
#include <vector>


void selectionSort(int arr[], int n);
int counterFunc(int arr[],int n);

int main(){

    std::string s;
    std::ifstream text;
    text.open("db.txt");

    std::ofstream output;
    output.open("dbnew.txt");

    std::string day,time,product_id,customer_id;
    //2D vector of string to place input parn in this 
    std::vector<std::string> v[4];
    int counter{};
    //geting input & save in vector v
    while(text){
      text>>day>>time>>product_id>>customer_id;
      //std::cout<<day<<" "<<time<<" "<<product_id<<" "<<customer_id<<std::endl;
      //int z=std::stoi(product_id);
      //int w=std::stoi(customer_id);
      
      v[0].push_back(day);
      v[1].push_back(time);
      v[2].push_back(product_id);
      v[3].push_back(customer_id);
      if(text){ 
      std::cout<<v[0][counter]<<" "<<v[1][counter]<<" "<<v[2][counter]<<" "<<v[3][counter]<<std::endl; 
      counter++; 
      }    
      
    }

    //vector to find out place of last parametre of one day
    std::vector<int> seprator;
    seprator.push_back(0);
    for (int i = 0; i < counter; ++i)
    {
    	if(v[0][i] != v[0][i+1])
    		seprator.push_back(i);
    }
    seprator.push_back(counter-1);

    

       //speration
       int i{},j{1};
       int fg{},kj{};
       int product_count[counter];
       int customer_count[counter];
       while( (i <= seprator[j]) &&(i != (counter-1) ) )
       {
            if(i==0)
            	fg=i-1;
            else
            	fg=i;

            if(i==0)
            	kj=i;
            else
            	kj=i+1;

       	    int arr1[ (seprator[j] - fg) ];
       	    int arr2[ (seprator[j] - fg) ];

       	    for(int k{}; k < (seprator[j] - fg) ;k++)
       	    {
       		    arr1[k]=std::stoi(v[2][ (k+kj) ]);
       		    arr2[k]=std::stoi(v[3][ (k+kj) ]);
       		    
       	     }

       		for(int zx{}; zx < (seprator[j] - fg) ;zx++)
       	    {
       	    	selectionSort(arr1,(seprator[j] - fg));
                selectionSort(arr2,(seprator[j] - fg));
       		    //std::cout<<arr1[zx]<<"  "<<arr2[zx]<<"\t"<< zx<<std::endl;

       	    }
       	    
       	    product_count[j-1]=counterFunc(arr1,(seprator[j] - fg));
       	    customer_count[j-1]=counterFunc(arr2,(seprator[j] - fg));
       	    //std::cout<<product_count[j-1]<<"ff*ff"<<customer_count[j-1]<<std::endl;
              std::cout<<v[0][seprator[j]]<<"] "<<product_count[j-1]<<"  "<<customer_count[j-1]<<std::endl;
              output<<v[0][seprator[j]]<<"] "<<product_count[j-1]<<"  "<<customer_count[j-1]<<std::endl;
         i=seprator[j];
         j++;
         if(j==static_cast<int>(seprator.size()))
         	break;


        }


	return 0;
}

void selectionSort(int arr[], int n) {
   int j{}, min{}, temp{};
   for (int i{}; i < n - 1; i++) {
      min = i;
      for (j = i + 1; j < n; j++)
         if (arr[j] < arr[min])
            min = j;

         temp = arr[i];
         arr[i] = arr[min];
         arr[min] = temp;
   }
}


int counterFunc(int arr[],int n){
	int s{};
	for (int i = 0; i < n; ++i)
	{
		if(arr[i] != arr[i+1])
		s++;
	}
	return s;
}





