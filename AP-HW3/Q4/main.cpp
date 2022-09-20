#include <iostream>
#include "human.h"
#include "oracle.h"
//#include "oracle.h"

int main() {

    Human h{"ALI", "BAHADORI", 4, 3, 25, 0, 0};
    Human gh{h};
    gh=h;
    //Human h1{};
    //std::cout<<h.getLastName()<<std::endl;
    Human* p1{new Human {"ALI", "BAHADORI", 4, 3, 25, 0, 0}};
    std::cout<<p1->getLastName()<<std::endl;
    Human* p2{new Human {"BAHAR", "SHAMS", 1, 2, 22, 1, 0}};
    std::cout<<p2->getLastName()<<std::endl;

    Oracle o1{"SHERVIN"};

    //married couple
    o1.marry(p1, p2);

    //creating new person
    Human* p3{};
    //Human* p33{};
    p3=*p1 + *p2;
    //p33=*p1 + *p2;
    //std::cout<<p33->getLastName()<<std::endl;
    std::cout<<"azxs"<<p1->children[0]->getLastName()<<std::endl;
    std::cout<<p3->getLastName()<<std::endl;
    std::cout<<p3->getEyeColor()<<std::endl;
    std::cout<<p3->getHairColor()<<std::endl;
    std::cout<<p3->getAge()<<std::endl;


    //Human* pp{new Human {"ALI", "BAHADORI", 4, 3, 25, 0, 0}}; 
    o1.isFamily(p1,p2);
    
    //setting the firstname of newborn
    if(p3->getGender())
        p3->setFirstName("MAHSHID");
    else
        p3->setFirstName("FARSHID");
    
    std::cout<<p3->getFirstName()<<std::endl;

    
    //increasing the age of newborn
    (*p3)++;
    std::cout<<p3->getAge()<<std::endl;

    //Human czf{"SAHIN", "REZAE", 0, 5, 58, 1, 5};
    Human* p4{new Human {"SHAHIN", "REZAEE", 0, 5, 58, 1, 1}};
    Human* p5{new Human {"FARHAD", "BAHADORI", 0, 6, 63, 0, 1}};
    //std::cout<<p4->children[0]->getLastName()<<std::endl;


    

    o1.setChild(p1, p4, p5);
    
    if(o1.isFamily(p5, p3))
        //std::cout<<"aloer"<<std::endl;
        std::cout<<o1.isFamily(p5, p3)<<std::endl;

    // Human** f1{o1.getFamily(p3)};
    if(o1.isFamily(p3, p5)) {

        std::cout << "the population of family is: " << o1.getPopulationOfFamily(p3) <<std::endl;

        Human** f1{o1.getFamily(p3)};
        //std::cout << f1[6]->getFirstName() << " ";
        //std::cout << "the name of each member of family: " ;

        for(int i{0}; i < o1.getPopulationOfFamily(p3); i++) {

            std::cout << f1[i]->getFirstName() << " ";
        }
        std::cout <<std::endl;
    }

    std::cout<<p3->mother->getFirstName()<<std::endl;
    std::cout<<p3->father->father->getFirstName()<<std::endl;
    std::cout<<(p3 == p3)<<std::endl;

    Human* p7{new Human {"REZA", "REZAEE", 0, 5, 15, 1, 1}};
    Human* p8{new Human {"HASHAN", "BAHADORI", 0, 6, 10, 0, 1}};
    o1.setChild(p7, p1, p2);
    o1.setChild(p8, p1, p2);
    
    p1->printChildren();
    //std::cout<<p1->children[2]->getFirstName()<<std::endl;
    





    //I insert to main this part to test isFamily 
    //and getFamily fuction

    /*Human* a1{new Human {"NASER", "REZAPOUR", 1, 2, 65, 0, 0}};

    Human* a2{new Human {"HASSAN", "KAVE", 7, 4, 26, 0, 0}};

    Human* a3{new Human {"OMID", "RAZI", 1, 2, 32, 0, 0}};

    Human* a4{new Human {"HASHEM", "MODARSI", 1, 4, 25, 0, 0}};

    Human* a5{new Human {"GHADER", "MAJD", 1, 4, 40, 0, 0}};


    Human* b1{new Human {"SARA", "NIAZI", 2, 1, 60, 1, 0}};
    
    Human* b2{new Human {"ZAHRA", "TAIE", 2, 1, 25, 1, 0}};
    
    Human* b3{new Human {"NASTARAN", "RASOLI", 2, 1, 23, 1, 0}};
    
    Human* b4{new Human {"ELENA", "VAZIRY", 3, 4, 22, 1, 0}};

    Human* b5{new Human {"SIMA", "BAGHERI", 3, 4, 28, 1, 0}};


    Oracle o2{"ALIREZA"};

    //married couple
    o2.marry(a1, b1);
    o2.marry(a2, b2);
    o2.marry(a3, b3);
    o2.marry(a4, b4);
    o2.marry(a5, b5);
 
    */   

    return 0;
}
