#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

void saveToFile(const std::string& filename, const std::vector<Book>& data)
{
    std::fstream fl(filename, std::ios::out);
    for (size_t i = 0; i < data.size() ; ++i)
    {
        fl << data[i].Author << std::endl;
        fl << data[i].Title << std::endl;
        fl << data[i].Year << std::endl;
    }
}
