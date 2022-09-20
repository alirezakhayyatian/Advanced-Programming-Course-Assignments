#include "oracle.h"
#include  <cmath>
//constructor
Oracle::Oracle(std::string Name){
	this->Name=Name;
}

bool Oracle::marry(Human* h1,Human* h2){

    if(	(h1->getAge()<18)  ||  (h2->getAge()<18) )
    	return false;
    if( ((h1->spouse)) != nullptr || ((h2->spouse))!=nullptr ) 
       return false;
     
    h1->spouse=h2;
    
    h2->spouse=h1;

   return true;
}


void Oracle::setChild(Human* child,Human* mom,Human* dad){

	child->father=dad;
	child->mother=mom;

    //std::cout<<"lll"<<(mom->getNumberOfChildren())<<std::endl;

	dad->setNumberOfChildren(dad->getNumberOfChildren()+1);
	mom->setNumberOfChildren(mom->getNumberOfChildren()+1);


    //std::cout<<"fsbn"<<(mom->getNumberOfChildren())<<std::endl;

    
	//dad->children[dad->getNumberOfChildren()]=child;
	//mom->children[mom->getNumberOfChildren()]=child;


	Human** arr=new Human*[dad->getNumberOfChildren()];
    for (int i = 0; i < dad->getNumberOfChildren()-1; ++i)
    {
    	arr[i]=dad->children[i];
    }
    arr[ (dad->getNumberOfChildren() - 1) ]=child;
    delete[] dad->children;
    dad->children=arr;
    arr=nullptr;
    delete arr;


    Human** arr1=new Human*[mom->getNumberOfChildren()];
    for (int i = 0; i < mom->getNumberOfChildren()-1; ++i)
    {
    	arr1[i]=mom->children[i];
    }
    arr1[ (mom->getNumberOfChildren() - 1) ]=child;
    delete[] mom->children;
    mom->children=arr1;
    arr1=nullptr;
    delete arr1;



}


void Base(int decimal,int transformer[]){
  int binary[5];
  for (int b = 0; b < 5; ++b)
    binary[b]=0;

  int z{0};
    
    while(decimal>0){
      binary[z]=decimal % 5;
      decimal=decimal / 5;
      z++;
      
    }
    int k{};
    
    for (int i = (4); i >= 0; i--)
    {
      transformer[k]=binary[i];
      //std::cout<<transformer[k]<<" ";
      k++;
    }
}

void Base_numberOfChildren(int decimal,int base,int transformer[]){
  int binary[5];
  for (int b = 0; b < 5; ++b)
    binary[b]=0;

  int z{0};
    
    while(decimal>0){
      binary[z]=decimal % base;
      decimal=decimal / base;
      z++;
      
    }
    int k{};
    
    for (int i = (4); i >= 0; i--)
    {
      transformer[k]=binary[i];
      //std::cout<<transformer[k]<<" ";
      k++;
    }
}





//{0,1,2,3,4}
//{ ,f,m,s,c}
bool Oracle::isFamily(Human* h1,Human* h2){

    //int z{};
    int arr1[5];
    int arr2[5];
    int arr3[5];
    int arr4[5];
    Human* t1=new Human{};
    Human* t2=new Human{};
    t1=h1;
    t2=h2;
    int num1 = t1->getNumberOfChildren();
    int num2 = t2->getNumberOfChildren();

    for (int a = 0; a < std::pow(num1,4)+1; ++a)
    {
     	for (int b = 0; b < std::pow(num2,4)+1; ++b)
     	{
    	    if(num1 != 0)
     		Base_numberOfChildren(a,num1,arr4);
    	    if(num2 != 0)
     		Base_numberOfChildren(b,num2,arr3);



     		for (int i = 0; i < std::pow(5,4); ++i)
     		{
	    
                for (int k = 0; k < std::pow(5,4); ++k)
		        {
			        Base(i,arr1);
			        Base(k,arr2);
			
			        for (int w = 0; w < 5; ++w)
			        {
				        if(arr1[w]==1 && (t1 != nullptr))
					    t1=t1->father;

				        if(arr1[w]==2 && (t1 != nullptr))
					    t1=t1->mother;

					    if(arr1[w]==3 && (t1 != nullptr))
					    t1=t1->spouse;

                        if(arr1[w]==4 && (t1 != nullptr) &&(num1 != 0)){
                	    //we spose
                	    t1=t1->children[ arr4[w] ];
                        }


                        if(arr2[w]==1 && (t2 != nullptr))
					    t2=t2->father;

				        if(arr2[w]==2 && (t2 != nullptr))
					    t2=t2->mother;

				        if(arr2[w]==3 && (t2 != nullptr))
					    t2=t2->spouse;

                        if(arr2[w]==4 && (t2 != nullptr) && (num2 != 0)){

                		t2 = t2->children[ arr3[w] ];
                        }

									
	        		}//w

                //std::cout<<k<<std::endl;
            
			    if(t1 == t2)
			    {
			    	t1=nullptr;
			    	t2=nullptr;
			    	delete[] t1;
			    	delete[] t2;
			        return true;
			    }   
			    t1=h1;
			    t2=h2;
		        }//k
            //std::cout<<"fff"<<std::endl;


	        }//i

     		
   	    }//b
    }//a 
	
    return false;
}


Human** Oracle::getFamily(Human* h1){

    int numberOfFamily{};
	Human** family{nullptr};

    int arr1[5];
    int arr2[5];
    Human* t1=new Human{};
    t1=h1;
    int num1 = t1->getNumberOfChildren();    
    
    for (int a = 0; a < std::pow(num1,4)+1; ++a)
    {
    	if(num1 != 0)
     	Base_numberOfChildren(a,num1,arr2);

    	for (int k = 0; k < std::pow(5,4); ++k)
	    {
	        Base(k,arr1);
			t1=h1;
			for (int w = 0; w < 5; ++w)
			{
				if(arr1[w]==1 && (t1 != nullptr))
			    t1=t1->father;

				if(arr1[w]==2 && (t1 != nullptr))
			    t1=t1->mother;

			    if(arr1[w]==3 && (t1 != nullptr))
			    t1=t1->spouse;

                if(arr1[w]==4 && (t1 != nullptr)  && (num1 != 0)){
                	    //we spose
                	t1=t1->children[ arr2[w] ];
                }
            }


            if(t1 != nullptr){
            	int counter{};
            	int bond=numberOfFamily;
            	for (int u = 0; u < bond+1; ++u){
            		if(numberOfFamily != 0)
            		{
            		    if(t1 == family[u])
            			    counter++;
            	    }
            	}
            		if(counter == 0){
                        numberOfFamily++;
            			Human** arr=new Human*[numberOfFamily];
                        for (int i = 0; i < numberOfFamily-1; ++i)
                        {
    	                    arr[i]=family[i];
                        }
                        //std::cout<<t1->getFirstName()<<std::endl;
                        arr[ numberOfFamily - 1 ]=t1;
                        delete[] family;
                        family=arr;
                        arr=nullptr;
                       delete arr;

            		}
            
            }



        }   
    }
    return family;
}


int Oracle::getPopulationOfFamily(Human* h){

    int s{};
	Human** population = this->getFamily(h);
    while(  population[s] != nullptr )
    	s++;
    s--;
    return s;

}














