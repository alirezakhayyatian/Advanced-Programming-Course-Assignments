#include <iostream>
#include <string>
#include <memory>
#include "ctext.h"
#include "stack.hpp"
#include <vector>
int main(){

    Stack<std::shared_ptr<CText>> stack;
    std::string base{"TEXT"};
    
    for(char a{'A'};a<='Z';a++)
       stack.push( std::make_shared<CText> (base+a) );
        
    int N{stack.getCount()};
    if(stack.isEmpty()){
        std::cout<<"stack is empty"<<std::endl;
        return -1;
    }

    for (int i = 0; i < N; ++i)
        std::cout<<stack.pop()->getText()<<std::endl;

    if(stack.isEmpty())
        std::cout<<"Stack is empty"<<std::endl;
    
    return 0;
}