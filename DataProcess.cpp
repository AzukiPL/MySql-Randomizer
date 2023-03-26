#pragma once
#include <iostream>
#include "records.cpp" // records.cpp includes columns
class DataProcess
{
private:
    columns cols;
    records recs;
    std::string tableName;

private:
    void GetVectors()
    {
        std::vector<std::string> fileNames[6]; // declaring all vectors i need
        std::string path[] = {
            "Columns/Date/",
            "Columns/DateTime/",
            "Columns/Decimal/",
            "Columns/Int/",
            "Columns/Time/",
            "Columns/Varchar/",
        };
        cols.directory.reserve(fileNames->size()); // reserving space in container for these vectors inside the columns class
        int i = 0;
        for (auto &name : fileNames)
        {
            cols.AddDirectory(path[i], name);
            i++;
        }
        cols.CheckDirectories(); // checks assigned directories and find files inside them
    }

    void AskTableName()
    {
        std::cout << "enter table name: ";
        std::cin >> tableName;
    }

    void OutputColumnNames()
    {
        std::cout << "INSERT INTO " << tableName << " (";
        int i = 0;
        for (auto &vec : cols.directory)
        {
            if (!vec.empty()) // if there file names inside vector directory = true, else move to next vector
            {
                if (i == 0)
                    std::cout << "\"" << vec[0] << "\""; // first column name cant start with "," because of SQL syntax
                for (auto &name : vec)
                {
                    if (i == 0)
                    {
                        i++;
                        continue;
                    }
                    std::cout << ",\"" << name << "\""; // yeah for some reason SQL requires " " for column names (I think it requires, lazy to check)
                }
            }
        }
        std::cout << ")";
    }

    void GetVariableType()
    {
        int i = 0;
        for (auto &vec : cols.directory)
        {
            if (!vec.empty())
            {
                for(auto& str : vec) {
                    std::string filePath = cols.filePath[i];
                    filePath.erase(filePath.begin(), filePath.begin() + 8);
                    filePath.erase(filePath.end() - 1, filePath.end());
                    std::cout << filePath << std::endl;
                }
            }
            i++;
        }
    }

public:
    void SQLRandomizer()
    {
        GetVectors();
        AskTableName();
        OutputColumnNames();
        GetVariableType();
    }
};
