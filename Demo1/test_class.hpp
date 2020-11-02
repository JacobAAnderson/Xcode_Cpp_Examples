//
//  test_class.hpp
//  Demo1
//
//  Created by Jacob Anderson on 8/3/20.
//  Copyright © 2020 Jacob Anderson. All rights reserved.
//

#ifndef test_class_hpp
#define test_class_hpp

#include <stdio.h>
#include <iostream>


class Test {
    std::string name;
    std::string txt;
    int num1;
    double num2;
    
    bool is_txt;
    bool is_num1;
    bool is_num2;
    
public:
    
    Test(std::string name);
    Test(std::string name_, int num);
    Test(std::string name_, double num);
    
    ~Test();
    
    std::string get_txt();
    
    double get_num();
    
    
    template<typename T>
    bool set_num(T input){
        
        if(typeid(T) == typeid(int)){
            num1 = input;
            is_num1 = true;
            return true;
            }
        else if (typeid(T) == typeid(double)){
            num2 = input;
            is_num2 = true;
            return true;
            }
        else{ std::cout << "\nUnreckognized data type!!\n\n";
            return false;
        }

    }
    
};


#endif /* test_class_hpp */
