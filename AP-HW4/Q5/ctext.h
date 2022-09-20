#include <iostream>
#include <string>

class CText{

public:
    CText()=default;
    CText(std::string str):s{str}{}
	
	std::string s;

    std::string getText(){return s;}



};