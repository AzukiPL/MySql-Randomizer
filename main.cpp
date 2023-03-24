#include <iostream>
#include "DataProcess.cpp"
DataProcess dadPro;

int main()
{
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
    dadPro.SQLInsert();
}
