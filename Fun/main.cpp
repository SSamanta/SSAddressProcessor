//
//  main.cpp
//  Fun
//
//  Created by Susim Samanta on 24/01/14.
//  Copyright (c) 2014 SusimSamanta. All rights reserved.
//

#include <iostream>
#include <fstream>
int main()
{
    void processAddress (std::string input);
    std:: string input;
    std::getline(std:: cin, input);
    processAddress(input);
    return 0;
}

std::string processAddress (std::string input) {
    std::ifstream file("LookUp.csv");
    std::string str;
    while (std::getline(file, str))
    {
        std:: cout << str << '\n';
    }
    
    std:: cout << input;
    return input;
}
