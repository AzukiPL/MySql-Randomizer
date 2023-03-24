#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "columns.cpp"

class records
{
    private:
        columns cols;
    public:
        std::vector<std::string> contentLine; // line of content inside file.txt
    public:
        // opens folder and stores its content inside vector
        void ReadFIle(std::string filePath, std::string file) {
            this->contentLine.clear();
            std::fstream columnFile;
            file =  filePath+file+".txt";
            columnFile.open(file, std::ios::in);
            if(columnFile.is_open()) {
                std::string line;
                while(std::getline(columnFile,line)) {
                    this->contentLine.emplace_back(line);
                }
                columnFile.close();
            }
        }

        // void ReadFile(std::string path, std::string file) { // sums path with file name, then opens it and pushes content of that file into vector
        //     std::fstream columnFile;
        //     file =  path+file+".txt";
        //     columnFile.open(file, std::ios::in);
        //     if(columnFile.is_open()) {
        //         std::string line;
        //         while(std::getline(columnFile,line)) {
        //             columnRecords.push_back(line);
        //         }
        //         fileVectors.push_back(columnRecords);
        //         // columnRecords.clear();
        //         columnFile.close();
        //     }
        // }
};
