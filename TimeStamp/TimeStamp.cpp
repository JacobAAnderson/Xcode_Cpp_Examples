//
//  main.cpp
//  TimeStamp
//
//  Created by Jacob Anderson on 8/5/20.
//  Copyright © 2020 Jacob Anderson. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <ctime>


long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n\n";
    
    //====== Time Stamps ============================================================================
    //____ #include <chrono> ____
    // In Seconds
    const auto p1 = std::chrono::system_clock::now();
    std::cout << "TimeStamp 1: " << std::chrono::duration_cast<std::chrono::seconds>(p1.time_since_epoch()).count() << "\t\t\t\t[s]\n";
    
    
    // In milliseconds
    int64_t milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "TimeStamp 2: " << milliseconds << "\t\t\t[mill-s]\n";
    
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds >(std::chrono::system_clock::now().time_since_epoch());
    int millis = milliseconds % 1000;
    std::cout << millis << "\n";
    
    
    // In microseconds
    int64_t microseconds = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "TimeStamp 3: " << microseconds << "\t\t[mico-s]\n";
    
    // In nanoseconds
    int64_t nanoseconds = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << "TimeStamp 4: " << nanoseconds << "\t[nano-s]\n";

    
    //____ #include <ctime> _____
    std::time_t time_ = std::time(nullptr);
    std::cout << "\nTimeStamp 5: " << time_ << "\t[s]\n";
    std::cout << "\nDate and Time: " << std::asctime(std::localtime(&time_)) << "\n\n";
    
    
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    //int mill = now -> tm_sec;
    
    char buffer[26];
    std::strftime(buffer, 26, "%F %T", now);
    std::cout << "Buffer: " << buffer << "\n";

    
    
    // ____ <chrono> & <ctime> ____
    // Using time point and system_clock
    std::cout << "Fibonacci Example\n\n";
    std::chrono::time_point<std::chrono::system_clock> start, end;
      
    start = std::chrono::system_clock::now();
    std::cout << "f(42) = " << fibonacci(42) << '\n';
    end = std::chrono::system_clock::now();
      
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
      
    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    
    std::cout <<"\n\n\n";
    return 0;
}
