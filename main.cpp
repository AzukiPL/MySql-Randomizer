#include <iostream>
#include "columns.cpp"
int main(int, char**) {
    columns cols;
    cols.CheckDirectories();
    // cols.columnInt.push_back("test test");
    for(std::string str : cols.columnInt) {
        std::cout << str << std::endl;
    }
        for(std::string str : cols.columnDecimalFloat) {
        std::cout << str << std::endl;
    }
}
