#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "columns.cpp"

class records
{
    private:
        std::vector<std::string> columnRecords;
        columns col;

    public:
        std::vector<std::vector<std::string>> fileVectors;

    private:
    
        void ReadFile(std::string path, std::string file) { // sums path with file name, then opens it and pushes content of that file into vector
            std::fstream columnFile;
            file =  path+file+".txt";
            columnFile.open(file, std::ios::in);
            if(columnFile.is_open()) {
                std::string line;
                while(std::getline(columnFile,line)) {
                    columnRecords.push_back(line);
                }
                fileVectors.push_back(columnRecords);
                // columnRecords.clear();
                columnFile.close();
            }
        }
        void GetRecords(std::string path, std::string file) {
            ReadFile(path, file);
            for(auto& line : columnRecords) {
                 std::cout << line << std::endl;
            }
        }
        void GetVariables(std::string path, std::vector<std::string> directory) {
            for(auto& str : directory) {
                GetRecords(path,str);
            }
        }
    public:
        void ReadRecords() {
            GetVariables("Columns/Int/", col.columnInt);
        }

    //         void GetRecords(std::string path) {
    //             for(auto& vec : fileVectors) {
    //                 for(auto& str : vec) {

    //                 }
    //             }


    //         ReadFile(path, file);
    //         for(auto& line : columnRecords) {
    //              std::cout << line << std::endl;
    //         }
    //     }
    // public:
    //     void ReadRecords(std::string path, std::string file) {
    //         GetRecords(path,file);
    //     }
};
