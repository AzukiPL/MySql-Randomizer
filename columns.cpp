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
        std::vector<std::vector<std::string>> directory; // Directory containing vectors of all file names
        std::vector<std::string> filePath; // Directory containing vectors of all file paths

    private:
        void Directory(std::string path, std::vector<std::string> &column) {
            for (const auto & entry : fs::directory_iterator(path)) {
                column.emplace_back(entry.path().generic_string()); // pushes list of paths for each file from inside directory path
            }
        }

        void GetFileNames(std::string path, std::vector<std::string> &column) { // use list with paths and convert it to file names only 
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
            for(int i =0; i < this->directory.size(); i++) {
                GetFileNames(this->filePath[i],this->directory[i]);
            }
        }
        void AddDirectory(std::string filePath, std::vector<std::string> &dirFileName) {
            this->directory.emplace_back(dirFileName);
            this->filePath.emplace_back(filePath);
        }

};
