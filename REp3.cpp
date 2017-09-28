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
    double s;
    s = sqrt((x1-x2) * (x1-x2) +(y1-y2) * (y1-y2));
    std::cout << s << std::endl;
    return 0;
}
