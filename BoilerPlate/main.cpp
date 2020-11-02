//
//  main.cpp
//  BoilerPlate
//
//  Created by Jacob Anderson on 8/5/20.
//  Copyright © 2020 Jacob Anderson. All rights reserved.
//

#include <iostream>
#include <fstream>
//#include <stdio.h>
#include <chrono>
#include <ctime>


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n\n";
    
    //====== Time Stamps ============================================================================
    // #include <chrono>
    int64_t timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "TimeStamp 1: " << timestamp << "\t[ms]\n";
    
    const auto p1 = std::chrono::system_clock::now();
    std::cout << "TimeStamp 2: " << std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count() << "\t\t[s]\n";
    
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
    
    
    // #include <ctime>
    std::time_t result = std::time(nullptr);
    std::cout << "TimeStamp 3: " << result << "\t\t[s]\n";
    std::cout << "\nDate and Time: " << std::asctime(std::localtime(&result)) << "\n\n";
    

    
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    char fileName [80];
    strftime (fileName,80,"/Users/jake/Desktop/%Y%m%d%H%M%S_output.txt",now);

    std::cout << "\n\nWriting to file:  " << fileName << "\n\n\n";
            
    // #include <fstream>
    std::ofstream myfile;
    myfile.open (fileName, std::ios_base::app);
    myfile << "Stuff Goes Here!!";
    myfile << "\n" << 8.62 << " + " << 35 << " = ?";
    myfile << std::endl;
    myfile.close();

    
    std::cout <<"\n\n\n";
    
    std::cerr << "What Do I Do??" << std::endl;
    exit(EXIT_FAILURE);
    
    
    
    return 0;
}
