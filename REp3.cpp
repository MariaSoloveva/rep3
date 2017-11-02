#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <random>
#include <string>
#include <vector>

std::string join(const std::vector<std::string>& vec, const std::string sep)
{
    std::string join;
    for (int i = 0; i < vec.size(); ++i)
    {
        if (i == vec.size() -1)
        {
            join += vec[i];
        }
        else
        {
            join = join + vec[i] + sep;
        }
    }
    return join;
}
float mean(const std::vector<float>& vec)
{
    double sum = 0;
    for (float f : vec)
    {
        sum += f;
    }
    return (sum / (vec.size()));
}
std::pair<float, float> minMax(const std::vector<float>& vec)
{
    std::pair<float, float> minMax1;
    minMax1.first = vec[0];
    minMax1.second = vec[0];
    for (float f : vec)
    {
         if (vec[i] > minMax1.second)
         {
             minMax1.second  = f;
         }
         else
         {
           if (minMax1.first > f)
           {
               minMax1.first = f66;
           }
         }
    }
    return (minMax1);
}
int argmax(const std::vector<float>& vec)
{
  int number = 0;
  float max = vec[0];
  for (size_t i = 1; i < vec.size(); ++i)
  {
      if ( vec[i] > max )
         {
             number = i;
             max = vec[i];
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
int erase(std::vector<float>& vec)
{
    float remember = 0;
    for (size_t i = 0; i < vec.size(); ++i)
    {
        if (vec[i] < 0)
        {
            remember = vec[i];
            vec.erase(vec.begin() + i);
            break;
        }
    }
  return remember;
}
std::string replacePhrase(const std::string& str, const std::string& old, const std::string& newstr)
{
    while (str.find(old) != std::string::npos)
    {
        std::string strCopy = str;
        size_t n = str.find(old);
        strCopy.replace(n + 1, old.length(), newstr);
    }
    return strCopy;
}
std::vector<std::string> split(const std::string& str, char sep)
{
    std::vector<std::string> vec;
    std::string a;
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (str[i] != ' ')
        {
            a.push_back(str[i]);
        }
        else if (str[i] == ' ')
        {
            a.push_back(sep);
        }
    }
    vec.push_back(a);
    return vec;
}
int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<float> vectorOne;
    for (size_t i = 0; i < n; ++i)
    {
        vectorOne.push_back((rand() % 10000) / 1000.0);
        std::cout << vectorOne[i] << " ";
    }
    std::cout << std::endl;
    std::cout << mean(vectorOne) << std::endl;
    std::pair<float, float> couple = minMax(vectorOne);
    std::cout << couple.first << " " << couple.second << std::endl;
    std::cout << "The number of the max element" << argmax(vectorOne) << std::endl;
    sort(vectorOne);
    std::cout << erase(vectorOne) << std::endl;
    std::cout << "Enter the string" << std::endl;
    std::string str;
    std::getline(std::cin, str);
    std::cout << "enter the phrase you want to edit" << std::endl;
    std::string old;
    std::getline(std::cin, old);
    std::cout << "Enter the phrase you would like to see instead of the old" << std::endl;
    std::string newstr;
    std::getline(std::cin, newstr);
    std::cout << "Old string : " << str << std::endl;
    str = replacePhrase(str, old, newstr);
    std::cout << "New string : " << str << std::endl;
    return 0;
}
