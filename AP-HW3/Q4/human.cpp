#include "human.h"
//constructor
Human::Human(std::string firstName1,std::string lastName1,int hairColor1, int eyeColor1, int age1,bool gender1, int numberOfChildren1)
{
	firstName=firstName1;
	lastName=lastName1;
	hairColor=hairColor1;
	eyeColor=eyeColor1;
	age=age1;
	gender=gender1;
	numberOfChildren=numberOfChildren1;
	children = new Human*[numberOfChildren];
	for (int i = 0; i < numberOfChildren; ++i)
	{
		children[i]=nullptr;
	}

}

//Defalt constructor
 Human::Human():Human{"","",0,0,0,0,0}{
	//std::cout<<"Defualt Constructor"<<std::endl;
}
//copy constructor
Human::Human(const Human& h){
	std::cout<<"Copy Constructor"<<std::endl;
	firstName=h.firstName;
	lastName=h.lastName;
	hairColor=h.hairColor;
	eyeColor=h.eyeColor;
	age=h.age;
	gender=h.gender;
	numberOfChildren=h.numberOfChildren;

    //father=new Human{};
	father = h.father;

	//mother = new Human{};
    mother = h.mother;

    //spouse = new Human{};
    spouse = h.spouse;
    
    
    children = new Human*[numberOfChildren];
    for (int i = 0; i < numberOfChildren; ++i)
    {
    	children[i]=h.children[i];
    }   
}
//distructor
Human::~Human(){
	//delete[] father;
	//delete[] mother;
	//delete[] spouse;

	/*for (int i = 0; i < numberOfChildren ; ++i)
	{
		delete[] children[i];
	}*/
	delete[] children;
}



bool Human::isChildOf(Human* h){
     if(this->father == h)
     	return 1;
     return 0;
}

bool Human::isMotherOf(Human* h){
	if(h->mother == this)
     	return 1;
     return 0;
    
}

bool Human::isFatherOf(Human* h){
	if(h->father == this)
     	return 1;
     return 0;
}


void Human::printChildren(){

	std::string* name=new std::string[numberOfChildren];

	int j{}, min{}, temp{};
	std::string t;
	for (int i = 0; i < numberOfChildren; ++i)
	{
		name[i]=children[i]->firstName;
	}
    for (int i{}; i < numberOfChildren - 1; i++) {
      min = i;
      for (j = i + 1; j < numberOfChildren; j++)
         if (children[j]->age < children[min]->age)
            min = j;

         temp = children[i]->age;
         children[i]->age = children[min]->age;
         children[min]->age = temp;
         //if(children[min] != nullptr )

         t=name[i];
         name[i]=children[min]->firstName;
         name[min]=t;

   }
   //std::cout<<"ghgsj"<<numberOfChildren<<std::endl;

   for (int i = 0; i < numberOfChildren; ++i)
   {
   	    //std::cout<<children[i]->firstName <<"  ";
   	      std::cout<<name[(numberOfChildren - i-1)] <<"  ";

   }
   std::cout<<std::endl;
   //std::cout<<"ghgsj"<<numberOfChildren<<std::endl;

   delete[] name;
	
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







Human* Human::operator+(Human& h){
    
    if(	spouse != &h ){
    	std::cout<<"you could not parent"<<std::endl;
    	//std::cout<<spouse<<std::endl;
    	//std::cout<<&h<<std::endl;
    	return nullptr;
    }
    Human* child{new Human{}};
    
    child->lastName=lastName;
    
    //generate atribute of child radnome
    //by srand
    srand((unsigned)time(NULL));
    if((rand()%2) == 0)
    	child->gender=gender;
    else
    child->gender=h.gender;

    if((rand()%2) == 0)
    	child->hairColor=hairColor;
    else
    child->hairColor=h.hairColor;

    if((rand()%2)==0)
    	child->eyeColor=eyeColor;
    else
    child->eyeColor=h.eyeColor;
    //increase number of children of father and mother
    numberOfChildren++;
    h.numberOfChildren++;

   //generate dynamic array and delete old array 
   Human** arr=new Human*[numberOfChildren];
    for (int i = 0; i < numberOfChildren-1; ++i)
    {
    	arr[i]=children[i];
    }
    arr[ (numberOfChildren - 1) ]=child;
    delete[] children;
    children=arr;
    arr=nullptr;
    delete[] arr;
   //generate dynamic array and delete old array 
    Human** arr1=new Human*[numberOfChildren];
    for (int i = 0; i < numberOfChildren-1; ++i)
    {
    	arr1[i]=h.children[i];
    }
    arr1[ (numberOfChildren - 1) ]=child;
    delete[] h.children;
    h.children=arr1;
    arr1=nullptr;
    delete arr1;


    //determine father and mother
    // of children 
    child->father=this;
    child->mother=&h;


    return child;

}

bool Human::operator>(const Human& h){
	if( age > h.age )
		return true;
	return false;
}

bool Human::operator==(const Human& h){

    if(firstName == h.firstName)
    if(lastName == h.lastName)
	if(hairColor == h.hairColor)
    if(eyeColor == h.eyeColor)
    if( age == h.age)
	if(gender == h.gender)
	if(numberOfChildren == h.numberOfChildren)
		if(father == h.father)
        if(mother == h.mother)
        if(spouse == h.spouse)
        {
            for (int i = 0; i < numberOfChildren; ++i){
         		if( children[i] != h.children[i])
         			return false;
            }
            return true; 
        }
    return false;    			
}   


Human& Human::operator=(const Human& h){

	std::cout<<"Operator = Copy version"<<std::endl;
	firstName=h.firstName;
	lastName=h.lastName;
	hairColor=h.hairColor;
	eyeColor=h.eyeColor;
	age=h.age;
	gender=h.gender;
	numberOfChildren=h.numberOfChildren;

    //father=new Human{};
	father = h.father;

	//mother = new Human{};
    mother = h.mother;

    //spouse = new Human{};
    spouse = h.spouse;
    
    //to protecte from free double
    children = new Human*[numberOfChildren];
    for (int i = 0; i < numberOfChildren; ++i)
    {
    	children[i]=h.children[i];
    }
    return *this;

}

/*Human& operator=(Human* h){
	std::cout<<"Operator = overload"<<std::endl;
}*/























