#include <iostream>
#include <vector>
#include "columns.cpp"
#include "records.cpp"
#include <algorithm>

columns cols;
records recs;
            
void PushVectors() {
    std::vector<std::string> 
        dateFileName,
        dateTimeFileName,
        decimalFileName,
        intFileName,
        timeFileName,
        varcharFileName;
    cols.directory.reserve(6);
    cols.AddDirectory("Columns/Date/", dateFileName); // id 0
    cols.AddDirectory("Columns/DateTime/", dateTimeFileName); // id 1
    cols.AddDirectory("Columns/Decimal/", decimalFileName); // id 2
    cols.AddDirectory("Columns/Int/", intFileName); // id 3
    cols.AddDirectory("Columns/Time/", timeFileName); // id 4
    cols.AddDirectory("Columns/Varchar/", varcharFileName); // id 5

    cols.CheckDirectories();
}

int main() {
    PushVectors();
        int i =0;
    for(auto& vec : cols.directory) {
        if(!vec.empty())
        for(auto& fileName : vec) {
            std::cout << fileName << std::endl;
            recs.ReadFIle(cols.filePath[i],fileName);
            for(auto& line : recs.contentLine) {
                std::cout << line << std::endl;
            }
        }
        i++;
    }
}
