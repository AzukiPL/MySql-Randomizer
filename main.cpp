#include <iostream>
#include <vector>
#include "columns.cpp"
#include "records.cpp"
int main(int, char**) {
    columns cols;
    records recs;
    cols.CheckDirectories();
    recs.ReadRecords();

    for(auto& elemtn : recs.fileVectors) {
        for(auto& str : elemtn) {
            std::cout << str << std::endl;
        }
    }
}
