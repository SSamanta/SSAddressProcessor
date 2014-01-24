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
    std::string processAddress (std:: string input);
    std::string input ;// = "ARIJIT, 192 POST OFFICE, SUITE";
    std::cout << "Enter your string:";
    std::getline(std::cin, input);
    std::string output = processAddress(input);
    std::cout << output << "\n";
    return 1;
}

std::string processAddress (std:: string input) {
    void replaceAll(std::string& str, const std::string& from, const std::string& to);
    std::ifstream file("LookUp.csv");
    std::string str;
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
    for( MyMap::const_iterator it = my_map.end(); it != my_map.begin(); --it )
    {
        std::string key = it->first;
        std::string value = it->second;
        // find and replace
        replaceAll(input, key, value);
    }
    
    std::string output = input ;
    return output;
}
bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
}
