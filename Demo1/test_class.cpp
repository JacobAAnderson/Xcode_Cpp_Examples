//
//  test_class.cpp
//  Demo1
//
//  Created by Jacob Anderson on 8/3/20.
//  Copyright © 2020 Jacob Anderson. All rights reserved.
//

#include "test_class.hpp"
#include <typeinfo>
#include <cmath>


Test::Test(std::string name_): name(name_) {
    std::cout << "\nCreating Class " << name_ << "\n";
    
    is_num1 = false;
    is_num2 = false;
    is_txt  = false;
}

Test::Test(std::string name_, int num): name(name_), num1(num)  {
    std::cout << "\n\nCreating Class " << name_ << "\n";
    
    is_num1 = true;
    is_num2 = false;
    is_txt  = false;
}

Test::Test(std::string name_, double num): name(name_), num2(num)  {
    std::cout << "\n\nCreating Class " << name_ << "\n";
    
    is_num1 = false;
    is_num2 = true;
    is_txt  = false;
}

Test::~Test(){ std::cout << "\nBye bye " << name << "!!\n";}

std::string Test::get_txt(){
    if(is_txt) return txt;
    else return "\0";
    }

double Test::get_num(){
    if(is_num1)      return num1;
    else if(is_num2) return num2;
    else {std::cout << "You have to enter a number first!!\n";
        return std::nan("2");
    }
}



/* ____ Snippit from Codecadomy ____
template <typename T>
void add_number(T numb){
  std::cout << "Adding: " << numb << std::endl;
  
  if(typeid(T) == typeid(double)) {
    num1 = numb;
    is_num1 = true;
    }
    
  else if(typeid(T) == typeid(int)){
    num2 =numb;
    is_num2 = true;
    }

  else std::cout << "\n\nCan not match class type!!\n\n";
  }
*/
