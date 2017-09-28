#include <iostream>
#include <string>
#include <math.h>

int main(){
    // Длина между двумя точками :
    double x1;
    std::cin >> x1;
    double y1;
    std::cin >> y1;
    double x2;
    std::cin >> x2;
    double y2;
    std::cin >> y2;
    double s = sqrt( ( x1-x2 ) * ( x1-x2 ) +( y1-y2 ) * ( y1-y2 ) );
    std::cout << s << std::endl;
// Нахождение периметра равнобедренной трапеции :
    std::cout << "Введите размеры большего и меньшего оснований и высоты" << std::endl;
    double bigBase;
    std::cin >> bigBase;
    double littleBase;
    std::cin >> littleBase;
    double height;
    std::cin >> height;
    double sum = sqrt( height * height + ( bigBase - littleBase ) * ( bigBase - littleBase ) / 4 );
    double perimeter = bigBase + littleBase + 2 * sum;
    std::cout << perimeter << std::endl;
    return 0;
}
