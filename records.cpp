#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class records
{
    public:
        std::vector<std::string> columnRecords;
    
    public:
        void ReadFile(std::string path, std::string file) { // sums path with file name, then opens it and pushes content of that file into vector
            std::fstream columnFile;
            file =  path+file+".txt";
            columnFile.open(file, std::ios::in);
            if(columnFile.is_open()) {
                std::string line;
                while(std::getline(columnFile,line)) {
                    columnRecords.push_back(line);
                }
                columnFile.close();
            }
        }

};
