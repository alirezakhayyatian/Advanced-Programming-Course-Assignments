#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include <string>
#include <ctime>

//Forward declaration
class Human;  
//void operator++()



class Human{
    
    public:
    Human(std::string firstName1,std::string lastName1,int hairColor1, int eyeColor1, int age1,bool gender1, int numberOfChildren1);
    explicit Human();
    Human(const Human&);
    ~Human();


    std::string getFirstName()const {return firstName;}
    std::string getLastName()const {return lastName;}
    int getHairColor()const {return hairColor;}
    int getEyeColor()const {return eyeColor;}
    int getAge()const {return age;}
    bool getGender()const {return gender;}
    int getNumberOfChildren()const {return numberOfChildren;}
    void setFirstName(std::string Name){firstName=Name;}
    void setNumberOfChildren(int num){numberOfChildren=num ;}


    bool isChildOf(Human*);
    bool isMotherOf(Human*);
    bool isFatherOf(Human*);

    void printChildren();


    Human* operator+(Human&);
    bool operator>(const Human&);
    bool operator==(const Human&);
    Human& operator=(const Human&);
    void operator++(){ age++; }   //pre
    void operator++(int){age++;}  //post

    //Human& operator=(Human*);
    

    private:
    std::string firstName{};	
    std::string lastName{};    	
    int hairColor, eyeColor, age, numberOfChildren;
    bool gender;
public:
    Human* father{nullptr};
    Human* mother{nullptr};
    Human* spouse{nullptr};
    Human** children{nullptr};
};



#endif