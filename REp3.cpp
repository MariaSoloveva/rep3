#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

void loadFromFile(const std::string& filename, std::vector<std::string>& data)
{
    std::ifstream fl(filename);
    std::string str;
    while (!fl.eof())
    {
        std::getline(fl, str);
        data.push_back(str);
    }
}
