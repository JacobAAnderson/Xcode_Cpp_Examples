//
//  main.cpp
//  Write_to_file
//
//  Created by Jacob Anderson on 8/5/20.
//  Copyright © 2020 Jacob Anderson. All rights reserved.
//

#include <iostream>
#include <fstream>

int main(int argc, const char * argv[]) {
    
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );

    char fileName [80];
    strftime (fileName,80,"/Users/jake/Desktop/%Y-%m-%d_%H%M%S_output.txt",now);

    std::cout << "\n\nWriting to file:  " << fileName << "\n\n\n";
            
    // #include <fstream>
    std::ofstream myfile;
    myfile.open (fileName, std::ios_base::app);
    myfile << "Stuff Goes Here!!";
    myfile << "\n" << 8.62 << " + " << 35 << " = ?";
    myfile << std::endl;
    myfile.close();

    
    std::cout <<"\n\n\n";
    return 0;
}
