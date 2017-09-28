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
    // Вывод трех любых чисел с двумя пробелами между ними :
    std::cout << "Введите три любые числа" << std::endl;
    std::string number1;
    std::cin >> number1;
    std::string number2;
    std::cin >> number2;
    std::string number3;
    std::cin >> number3;
    std::string message1 = number1 + "  " + number2 + "  " + number3;
    std::cout << message1 << std::endl;
// Вычисление значения функции1 :
    std::cout << "Введите число а" << std::endl;
    double a = 0;
    std::cin >> a;
    double x = 12 * a * a + 7 * a - 12;
    double y = 3 * x * x * x + 4 * x * x - 11 * x + 1;
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    // Определение плотности по объему и массе :
    std::cout << "Введите объем и массу" << std::endl;
    double volume;
    std::cin >> volume;
    double weight;
    std::cin >> weight;
    double dentisy = weight / volume;
    std::cout << dentisy << std::endl;
// Решение функции :
    std::cout << "Введите число а,b" << std::endl;
    double a1;
    std::cin >> a1;
    double b;
    std::cin >> b;
    double x0 = -b / a1;
    std::cout << x0 << std::endl;
    return 0;
}
