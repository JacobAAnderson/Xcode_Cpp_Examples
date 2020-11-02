//
//  main.cpp
//  Demo1
//
//  Created by Jacob Anderson on 8/3/20.
//  Copyright © 2020 Jacob Anderson. All rights reserved.
//

#include <iostream>
#include "test_class.hpp"

using namespace std;

// ____ Templates and overloading functions ____
template<typename T1, typename T2>
T1 fnx1(T1 in1, T2 in2 ){return in1 + in2;}

template<typename T1, typename T2>
T1 fnx1(string txt, T1 num1, T2 num2){
    cout << "\n" << txt << " is " << num1 << " and " << num2 << endl;
    return num1 + num2;
}

int    fnx2( int in1,    int in2 )   { return in1 * in2;}
double fnx2( double in1, double in2) { return in1 * in2;}

string fnx2( string in1, string in2){
    cout << in1 << " + " << in2 << endl;
    return in1 + " + " + in2;
    }



// ___ Passing by referance _______________
int triple1(int i){   // Not passing by referance, the computer must make a coppy of i
    i = i*3;
    return i;
}

int triple2(int &i){   // Passing by referance, the computer does not coppy i but the input value gets modified aswell
    i = i*3;
    return i;
}


int square(int const &i) { // Pass by referance but do not modify the input source --> saves computer from coppying the soure value
  return i * i;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    
    // ____ Get Keyboard input ____________
/*  cout << "___ Keyboard Input ____\n";
    double input;
    cout << "\nGive us a number: ";
    cin >> input;
    cout << " You said: " << input << "\n";
*/
    // ____ Functions _____________________
    cout << "\n\n____ Function Struff ____\n";
    cout << fnx1( 3.2, 6) << endl;
    cout << fnx1("who", 89.23, 90);
    
    cout << fnx2( 1, 5) << endl;
    cout << fnx2( 1.4, 6.9) << endl;
    cout << fnx2( "1.4", "5.6") << endl;
    
    string num1 = "1.4 ";
    
    cout << fnx1( num1, "5.6") << endl;
    
    
    // ____ Classes _________________________
    cout << "\n\n_____ Classes _____\n";
    Test test1("Test1");
    cout << test1.get_num();
    
    if (test1.set_num(2)) cout << "\nNumber has been set to " << test1.get_num() << "\n";
    else cout << "\nNumber could not be set\n";
    
    
    Test test2("Test2", 5);
    cout << test2.get_num();
    
    Test test3("Test3", 25.3);
    cout << test3.get_num();
    
    
    // ___ Passing By Referance ____________
    cout << "\n\n Passing by referance ____\n";
    int i = 1;
    cout << "\n\nTriple1 \n";
    cout << triple1(i) << endl;
    cout << triple1(i) << endl;
    
 
    cout << "\nTriple2 \n";
    cout << triple2(i) << endl;
    cout << triple2(i) << endl;
    
    cout << "\nsquare\n";
    int side = 5;
    cout << square(side) << "\n";
    
    // ____ Address operator ________
    int power = 10;
    cout << "\nPower int value: " << power << "\n";
    cout << "Power Address in memory: " << &power << "\n";
    
    
    // ___ Pointers _______________________
    cout << "\n\n____ Pointers _____\n";
    power = 9000;
    
    // Create pointer
    int* ptr = &power;
    
    // Create a null pointer
    int* ptr2 = nullptr;
    
    ptr2 = &side;
    
    // Print ptr
    std::cout << "Power Address: " << ptr << "\n";
    
    // Print *ptr
    std::cout << "Power: " << *ptr << "\n";
    std::cout << "Side:  " << *ptr2 << "\n";
    
    
    cout <<"\n\nEl Finito\n";
    return 0;
}
