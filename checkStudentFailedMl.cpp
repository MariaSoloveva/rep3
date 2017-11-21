#include "lab08.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void loadFromFile(const std::string& filename, std::vector<Book>& outData)
{
    Book book1;
    std::ifstream fl(filename);
    std::string str;
    while (!fl.eof())
    {
        str.clear();
        std::getline(fl, str);
        book1.Author = str;
        std::getline(fl, str);
        book1.Title = str;
        std::getline(fl, str);
        book1.Year = atoi(str.c_str());
        outData.push_back(book1);
    }
}
