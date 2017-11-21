#include"lab08.hpp"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

void saveToFile(const std::string& filename, const Groups& groups)
{
    std::fstream fl(filename, std::ios::out);
    fl << groups.size() << std::endl;
    for (const auto& e : groups)
    {
        fl << e.first << std::endl;
        for (size_t i = 0; i < e.second.size(); ++i)
        {
            fl << e.second[i].Name << std::endl;
            fl << e.second[i].Year << std::endl;
            fl << e.second[i].RecordBook.size() << std::endl;
            for (const auto& a : e.second[i].RecordBook)
            {
                fl << a.first << std::endl;
                fl << a.second << std::endl;
            }
        }
        std::cout << std::endl;
    }
}
