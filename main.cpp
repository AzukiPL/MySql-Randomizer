#include <iostream>
#include "columns.cpp"
#include "records.cpp"
int main(int, char**) {
    columns cols;
    records recs;
    cols.CheckDirectories();
    // cols.columnInt.push_back("test test");
    for(std::string str : cols.columnInt) {
        std::cout << str << std::endl;
    }
        for(std::string str : cols.columnDecimal) {
        std::cout << str << std::endl << std::endl << std::endl;
    }
    recs.ReadFile("Columns/Int/",cols.columnInt[0]);
    std::cout << recs.columnRecords[4];
}
