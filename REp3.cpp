#include "lab05.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

float mean(const std::vector<float>& vec)
{
    double sum = 0;
    for (unsigned int i = 0; i < vec.size; ++i)
    {
        sum += vec[i];
    }
    return (sum / (vec.size));
}
std::pair<float, float> minMax(const std::vector<float>& vec)
{
    minMax.first = vec[0];
    minMax.second = vec[0];
    for (int i = 1; i < n; ++i)
    {
         if (vec[i] > minMax.second)
         {
             minMax.second  = vec[i];
         }
         else
         {
           if (minMax.first < vec[i])
           {
               minMax.first = vec[i];
           }
         }
    }
    return (minMax.first, minMax.second);
}
int argmax(const std::vector<float>& vec)
{
  int number = 0;
  float max = vec[0];
  for (int i = 1; i < n; ++i)
  {
      if ( v[i] > Max )
         {
             number = i;
         }
  }
  return number;
}
void sort(std::vector<float>& vec)
{
    int remember = 0;
    for (int i = 0; i < vec.size() - 1; ++i)
    {
        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[i] > vec[j])
            {
                std::swap(vec[i], vec[j]);
            }
        }
    }
}
int erase(std::vector<int>& vec)
{
    int m = 0;
    float remember = 0;
    for (int i = m; i < vec.size(); ++i)
    {
        if (vec[i] < 0)
        {
            vec.erase(vec.begin() + i);
            remember = vec[vec.begin() + i];
            break;
        }
    }
  return remember;
}
std::string replace(const std::string& str, const std::string& old, const std::string& new)
{
    while (old.find(str) != std::string::npos)
    {
        size_t n = old.find(str);
        old.replace(n + 1, str.length(), new);
    }
    return str;
}
int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<float> vectorOne(n);
    for (int i = 0; i < n; ++i)
    {
        vectorOne.push_back(rand());
        std::cout << vectorOne[i] << " ";
    }
    std::cout << std::endl;
    std::cout << mean(vectorOne) << std::endl;
    std::pair<float, float> couple = minMax(vectorOne);
    std::cout << "Номер максимального элемента" << argmax(vectorOne) << std::endl;
    sort(vectorOne);
    erase(vectorOne);
    std::string str;
    std::getline(cin,str);
    str::string old;
    str::string newstr;
    str = replace(str, old, newstr);
    return 0;
}
