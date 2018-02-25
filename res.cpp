#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

using ui64 = unsigned long long int;
using byte = unsigned char;
std::string BytesToHex(const std::vector<ui64> &bytes)
{
    std::string str;
    for (size_t i = 0; i < bytes.size(); ++i)
    {
        str.push_back(static_cast<unsigned char>(bytes[i]));
    }
    return str;
}
std::vector<ui64> BytesFromHex(const std::string &str)
{
    std::vector<ui64> bytes;
    for (size_t i = 0; i < str.size(); ++i)
    {
        bytes.push_back(static_cast<ui64>(str[i]));
    }
    return bytes;
}
ui64 Degree(ui64 Number,ui64 b,ui64 N)
{
    ui64 num = 1;
    for (ui64 i = 0; i < b; ++i)
    {
        num *= Number;
    }
    return num % N;
}
std::vector<byte> Encrypti(const std::vector<ui64> &message)
{
    std::vector<byte> bytes;
    for (size_t i = 0; i < message.size(); ++i)
    {
        std::cout << Degree(message[i], 7, 33) << std::endl;
        //bytes.push_back(static_cast<byte>(Degree(message[i], 7, 33)));
    }
    return bytes;
}
std::vector<byte> Encrypt(const std::string &message)
{
    std::vector<byte> bytes(message.size());
    for (size_t i = 0; i < message.size(); ++i)
    {
        std::cout << Degree((ui64)message[i], 3 , 9173503) << std::endl;
        bytes[i] = (unsigned char)Degree((ui64)message[i], 3 , 9173503);
    }
    return bytes;
}
std::string Decrypt(const std::vector<byte> &cipherText)
{
    std::string bytes;
    std::vector<ui64> degree(cipherText.size());
    for (size_t i = 0; i < cipherText.size(); ++i)
    {
        degree[i] = Degree((ui64)cipherText[i], 6111579, 9173503);
        std::cout << (unsigned char)degree[i] << std::endl;
        //bytes.push_back(reinterpret_cast<char>(Degree((ui64)cipherText[i], 6111579, 9173503)));
    }
    return bytes;
}
int main()
{
    std::string str = "klm";
    //std::getline(std::cin, str);
    //std::vector<ui64> x = BytesFromHex(str);
    //for(auto s : x)
    //    std::cout << s << std::endl;
    const std::vector<byte> bytes = Encrypt(str);
    std::string str1 = Decrypt(bytes);
    std::cout << str1 << std::endl;
    //for(auto s : bytes)
        //std::cout << s << std::endl;
    //std::string str1 = BytesToHex(x);
    //std::cout << str1 << std::endl;
    return 0;
}
