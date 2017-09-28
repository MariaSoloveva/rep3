#include <iostream>
#include <string>
#include <math.h>

int main(){
// Нахождение периметра равнобедренной трапеции :
    std::cout << "Введите размеры большего и меньшего оснований и высоты" << std::endl;
    double bigBase;
    std::cin >> bigBase;
    double littleBase;
    std::cin >> littleBase;
    double height;
    std::cin >> height;
    double sum = sqrt(height * height + (bigBase - littleBase) * (bigBase - littleBase) / 4);
    double perimeter = bigBase + littleBase + 2 * sum;
    std::cout << perimeter << std::endl;
    return 0;
}
