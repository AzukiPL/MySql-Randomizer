#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <filesystem>
#include <algorithm>
namespace fs = std::filesystem;

class columns
{

    public:
        std::vector<std::string> 
            columnDate,
            columnTime,
            columnDateTime,
            columnDecimalFloat,
            columnInt,
            columnVarchar;

    private:
        void Directory(std::string path, std::vector<std::string> &column) {
            for (const auto & entry : fs::directory_iterator(path)) {
                column.push_back(entry.path().generic_string()); // assigns array of paths for each file inside directory path
            }
        }

        void GetFileNames(std::string path, std::vector<std::string> &column) { // use array with paths and convert it to file names only 
            Directory(path, column);
            if(!column.empty()) {    
                int i=0;
                for (std::string text: column) {
                    text.erase(text.begin(),text.begin() + path.size());
                    text.erase(text.end()-4,text.end());
                    column[i] = text;
                    i++;
                }
            }

        }

    public:
        void CheckDirectories() {
            GetFileNames("Columns/Int/", columnInt);
            GetFileNames("Columns/Decimal/", columnDecimalFloat);

        }

};
