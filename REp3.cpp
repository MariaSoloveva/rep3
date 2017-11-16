#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

void saveToFile(const std::string& filename, std::vector<std::string>& data)
{
    std::ofstream fl(filename);
    for (int i = 0; i < data.size(); ++i)
    {
        fl << data[i];
        if (i < data.size() - 1)
            fl << std::endl;
    }
}
