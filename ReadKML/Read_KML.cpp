//
//  main.cpp
//  Read_KML
//
//  Created by Jacob Anderson on 9/25/20.
//  Copyright © 2020 Jacob Anderson. All rights reserved.
//

// reading a text file
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<sstream>

using namespace std;



bool is_number(const std::string& s)
{
    string::const_iterator it = s.begin();
    while ( it != s.end() && ( isdigit(*it) || ispunct(*it) ) ) ++it;
    return !s.empty() && it == s.end();
}



int main () {
    string line;
    string coordinates;
    string lastLine;
  
    ifstream myfile ("/Users/jake/Riptide/MOOS_Logs/TestLake/tmp/Test_Path2.kml");
  
    if (myfile.is_open())
    {
        cout << setprecision(13);
        cout << "Reading file" << endl;
        
        // --- Read teh KML File ---
        while ( getline (myfile,line) && line.compare(3,15,"<coordinates>") != 0 ); // Find the coordinates
        
        getline(myfile,coordinates);            // Get Coordinates
        getline(myfile,lastLine);               // Get the next line to make sure we have all the coordinates
        
//        cout << '\n' << coordinates << '\n';                  // Dispaly the coordinates
        
        if(line.compare(3,15,"<coordinates>") != 0 ) cout << "\n\n!!Last Line was not '<coordinates>'!!" << endl; // Make Sure we got all of the coordinates
      
        myfile.close();
        
        // --- Parse the Coordinate string ---
        vector<vector<double> > result;
        stringstream s_stream(coordinates); //create string stream from the string
        while(s_stream.good()) {
            string substr1, substr2, substr3;
            getline(s_stream, substr1, ','); //get first string delimited by comma  --> longitude
            getline(s_stream, substr2, ','); //get second string delimited by comma --> Latitude
            getline(s_stream, substr3, ' '); //get third string delimited by space  --> altitude (not a valid field)
            
            
            if( is_number(substr1) && is_number(substr2)){
            
                double lon = stod(substr1);
                double lat = stod(substr2);
            
                cout << "Lat: " << lat << ",  " << substr2 << '\t\t';
                cout << "Lon: " << lon << ",  " << substr1 << '\n';
            
                result.push_back({lon, lat});
            }
        }
        
        cout << "\n\n\n";
        for(int i = 0; i<result.size(); i++) {    //print all splitted strings
           cout << result[i][0] << '\t' << result[i][1] << endl;
        }
        
    }

    
    
    
    else cout << "Unable to open file";

return 0;
}
