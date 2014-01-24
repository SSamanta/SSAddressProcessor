//
//  main.cpp
//  Fun
//
//  Created by Susim Samanta on 24/01/14.
//  Copyright (c) 2014 SusimSamanta. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
int main()
{
    char * processAddress (char *input );
    char *input = "ARIJIT, 192 POST OFFICE, SUITE";
    char *output = processAddress(input);
    std::cout << output;
    return 0;
}

char * processAddress (char *input ) {
    char *output = input;
    
    std::ifstream file("LookUp.csv");
    std::string str;
    std::map<std::string, std::string> myMap;
    while (std::getline(file, str))
    {
        std:: cout << str << '\n';
        std::string delimiter = ",";
        std::string token1 = str.substr(0, str.find(delimiter));
        std::string token2 = str.substr(token1.length()+1, str.find(delimiter));
        std:: cout << token1 << token2 << '\n';
        myMap[token1] = token2;
    }
    return output;
}
