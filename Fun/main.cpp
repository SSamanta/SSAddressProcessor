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
    std::cout << output << "\n";
    return 0;
}

char * processAddress (char *input ) {
    char *output = input;
    
    std::ifstream file("LookUp.csv");
    std::string str;
    //std::map<std::string, std::string> myMap;
    typedef std::map<std::string, std::string> MyMap;
    MyMap my_map;
    while (std::getline(file, str))
    {
        std::string delimiter = ",";
        std::string token1 = str.substr(0, str.find(delimiter));
        std::string token2 = str.substr(token1.length()+1, str.find(delimiter));
        my_map[token1] = token2;
    }
    // Map Enumeration
    for( MyMap::const_iterator it = my_map.begin(); it != my_map.end(); ++it )
    {
        std::string key = it->first;
        std::string value = it->second;
        std:: cout << key << " : " << value << "\n";
    }
    
    return output;
}
