#include <iostream>
#include <vector>
#include <array>
#include "columns.cpp"
#include "records.cpp"
#include <algorithm>

columns cols;
records recs;
            
void PushVectors() {
    

    std::vector<std::string> fileNames[6]; // declaring all vectors i need
    std::string path[] = {
        "Columns/Date/",
        "Columns/DateTime/",
        "Columns/Decimal/",
        "Columns/Int/",
        "Columns/Time/",
        "Columns/Varchar/",
    };
    cols.directory.reserve(fileNames->size()); // reserving space in container for these vectors inside the class

    int i = 0;
    for(auto& name : fileNames) {
    cols.AddDirectory(path[i], name);
    i++;
    }

    cols.CheckDirectories(); //checks assigned directories to find files inside them
}

int main() {
    PushVectors();
                                    //     int i =0;
                                    // for(auto& vec : cols.directory) {
                                    //     if(!vec.empty())
                                    //     for(auto& fileName : vec) {
                                    //         std::cout << fileName << std::endl;
                                    //         recs.ReadFIle(cols.filePath[i],fileName);
                                    //         for(auto& line : recs.contentLine) {
                                    //             std::cout << line << std::endl;
                                    //         }
                                    //     }
                                    //     i++;
                                    // }
    std::string tableName;
    std::cout << "enter table name: ";
    std::cin >> tableName;
    system("cls");
    std::cout << "INSERT INTO " << tableName << " (";
    int i =0;   
    for(auto& vec : cols.directory) {
        if(!vec.empty()) {
            if(i==0)
            std::cout << "\"" << vec[0] << "\"";
            for(auto& name : vec) {
                if(i == 0) {
                    i++;
                    continue;
                }
                std::cout << ",\"" << name << "\"";
            }
        }
    }
    std::cout << ") VALUES";

}
