#include <cmath>
#include <iostream>
#include <vector>

int strstrFind(const std::string& str, const std::string& substr)
{
    for (int i = 0; i < str.length() - substr.length(); ++i)
    {
        bool flag = true;
        for (int j = 0; j < substr.length(); ++j)
            if (substr[j] != str[i + j])
            {
                flag = false;
                break;
            }
        if (flag)
            return i;
    }
    return -1;
}
using ui64 = long long int;
int rkFind(const std::string& str, const std::string& substr)
{
    ui64 lenStr = str.length();
    ui64 lenSubstr = substr.length();
    const int p = 53;
    std::vector<ui64> degree(lenStr);
    degree[0] = 1;
    for (size_t i = 1; i < lenStr; ++i)
        degree[i] = degree[i - 1] * p;
    std::vector<ui64> hashesOfPrefix(lenStr);
    for (size_t i = 0; i < lenStr; ++i)
    {
        hashesOfPrefix[i] = (str[i] - 'a' + 1) * degree[i];
        if (i)
            hashesOfPrefix[i] += hashesOfPrefix[i - 1];
    }
    ui64 hashOfStr = 0;
    for (size_t i = 0; i < lenSubstr; ++i)
        hashOfStr += (substr[i] - 'a' + 1) * degree[i];
    for (size_t i = 0; i < lenStr - lenSubstr + 1; ++i)
    {
        ui64 cur_h = hashesOfPrefix[i + lenSubstr - 1];
        if (i)
            cur_h -= hashesOfPrefix[i - 1];
        if (cur_h == hashOfStr * degree[i])
            return i;
    }
}
std::vector<int> findPrefix(std::string s) {
    int n = s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; ++i) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) ++j;
        pi[i] = j;
    }
    return pi;
}
int kmpFind(const std::string& str, const std::string& substr)
{
    int n = str.length();
    int m = substr.length();
    std::vector<int> pi = findPrefix(substr);
    int q = 0;
    for (int i = 0 ; i < n; ++i)
    {
        while (q > 0 && substr[q + 1] != str[i])
            q = pi[q];
        if (substr[q + 1] == str[i])
            q = q + 1;
        if ((q + 1 == m)  && (substr[0] == str[i - q]))
            return i - m + 1;
    }
}
int main()
{
    const std::string str = "wehfbkfjwkabcabcdefjwkabcabcd";
    const std::string substr = "abcabcd";
    std::cout << strstrFind(str, substr) << std::endl;
    std::cout << rkFind(str, substr)<< std::endl;
    std::cout << kmpFind(str, substr)<< std::endl;
    return 0;
}
