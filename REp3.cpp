#include <iostream>
#include <string>
#include <math.h>

int main(){
// Вывод числа Пи, округленного до сотых :
    std::cout << "pi = 3.14" << std::endl;
// Вывод чисел 1/13/49 c одним пробелом между ними :
    std::cout << "1 13 49" << std::endl;
//Вывод чисел 1/13/49 разделенные заданым символом :
    std::cout << "Введите знак" << std::endl;
    std::string sign1;
    std::cin >> sign1;
    std::string message = "1" + sign1 + "13"+sign1+"49";
    std::cout << message << std::endl;
    return 0;
}
