//
//  main.cpp
//  Date_Time
//
//  Created by Jacob Anderson on 8/7/20.
//  Copyright © 2020 Jacob Anderson. All rights reserved.
//

#include <iostream>
#include <sys/time.h>
#include <unistd.h>


int main(int argc, const char * argv[]) {
    
    char date_buffer[50];       // Buffer to format date and time
    char usec_buffer[50];       // Buffer to add microseconds to date & time
    long usec;                  // variable to hold useconds
    struct tm* tm_info;         // Structures for time values
    struct timeval tv;

    unsigned int usecs = 3450;  // Number of microsseconds to pause for
    

    for(int i = 0; i < 200; i++){                               // Make some time pass

        gettimeofday(&tv, NULL);                                // Get current time
    
        usec = tv.tv_usec;                                      // Get uSeconds
    
        tm_info = localtime(&tv.tv_sec);                        // Get current time in local format

        strftime(date_buffer, 50, "%F %T", tm_info);            // Format data and time --> YY/mm/DD HH:MM:SS
    
        sprintf(usec_buffer, "%s.%06ld", date_buffer, usec);    // Add useconds to time --> YY/mm/DD HH:MM:SS.zzzzzz
    
        std::cout << usec_buffer << "\n";                       // Display formated date and time
        
        usleep(usecs);                                          // Pause for x uSeconds --> make some time pass
        
    }
    
    
    std::cout << "\n\n\n";
    return 0;
}
