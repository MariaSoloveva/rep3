#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

float mean(const std::vector<float>& vec)
{
    double sum = 0;
    for (size_t i = 1; i < vec.size(); ++i)
    {
        sum += vec[i];
    }
    return (sum / (vec.size()));
}
std::pair<float, float> minMax(const std::vector<float>& vec)
{
    float minMax.first = vec[0];
    float minMax.second = vec[0];
    for (size_t i = 1; i < vec.size(); ++i)
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
  for (size_t i = 1; i < vec.size; ++i)
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
    for (size_t i = 0; i < vec.size() - 1; ++i)
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
    float remember = 0;
    for (size_t i = 0; i < vec.size(); ++i)
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
std::string replace(const std::string& str, const std::string& old, const std::string& newstr)
{
    while (old.find(str) != std::string::npos)
    {
        size_t n = old.find(str);
        old.replace(n + 1, str.length(), newstr);
    }
    return str;
}
int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<float> vectorOne(n);
    for (size_t i = 0; i < vectorOne.size(); ++i)
    {
        vectorOne.push_back(rand());
        std::cout << vectorOne[i] << " ";
    }
    std::cout << std::endl;
    std::cout << mean(vectorOne) << std::endl;
    std::pair<float, float> couple = minMax(vectorOne);
    std::cout << "The number of the max element" << argmax(vectorOne) << std::endl;
    sort(vectorOne);
    erase(vectorOne);
    std::cout << "Enter the string" << std::endl;
    std::string str;
    std::getline(std::cin, str);
    std::cout << "enter the phrase you want to edit" << std::endl;
    str::string old;
    std::getline(std::cin, old);
    std::cout << "Enter the phrase you would like to see instead of the old" << std::endl;
    str::string newstr;
    std::getline(std::cin, newstr);
    std::cout << "Old string : " << str << std::endl;
    str = replace(str, old, newstr);
    std::cout << "New string : " << str << std::endl;
    return 0;
}
