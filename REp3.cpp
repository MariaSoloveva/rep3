#include <iostream>
#include <string>
#include <math.h>

int main(){
// Нахождение площади кольца :
    std::cout << "Введите внутренний и внешний радиус" << std::endl;
    double littleRadius;
    std::cin >> littleRadius;
    double bigRadius;
    std::cin >> bigRadius;
    double square = 3.14 * (bigRadius*bigRadius - littleRadius * littleRadius);
    std::cout << square << std::endl;
// Нахождение площади кольца :
    std::cout << "Введите длину ребра" << std::endl;
    double rib;
    std::cin >> rib;
    double volumeCube;
    volumeCube = rib * rib * rib;
    double surfaceArea;
    surfaceArea = 6 * rib * rib;
    std::cout << volumeCube << std::endl;
    std::cout << surfaceArea << std::endl;
// Нахождение объема квадрата :
    std::cout << "Введите сторону квадрата, чтобы узнать периметр" << std::endl;
    double side;
    std::cin >> side;
    double area = 4 * side;
    std::cout << area << std::endl;
// Нахождение радиуса окружности :
    std::cout << "Введите радиус окружности, чтобы узнать диаметр" << std::endl;
    double radius;
    std::cin >> radius;
    double deameter = 2 * radius;
    std::cout << deameter << std::endl;
    return 0;
}
