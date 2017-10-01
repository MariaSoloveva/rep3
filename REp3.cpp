#include <iostream>
#include <string>
#include <math.h>

int main(){
//Каждое из чисел X,Y  нечетное
    std::cout << " X=?,Y=?" << std::endl;
    int x = 0;
    std::cin >> x;
    int y = 0;
    std::cin >> y;
    if (fmod(x, 2) ==0){
        std::cout << x << " even number" << std::endl;
    } else {
        std::cout << x << " odd number" << std::endl;
    }
    if (fmod(y, 2) ==0){
        std::cout << y << " even number" << std::endl;
    } else {
        std::cout << y << " odd number"  << std::endl;
    }
//Только одно число меньше 20
    if (((x < 20) && (y >= 20)) || ((x >= 20) && (y < 20))){
        std::cout <<"Only one number < 20" << std::endl;
    } else {
        std::cout << "Not only one number < 20" << std::endl;
    }
//Хотя бы 1 из чисел равно 0
    if ((x == 0) || (y == 0)){
        std::cout << "At least 1 of the numbers is 0" << std::endl;
    } else {
        std::cout << "The condition is not executed" << std::endl;
    }
//Каждое число отрицатально
    int z = 0;
    std::cin >> z;
    if ((x < 0) && (y < 0) && (z < 0)){
        std::cout << "Each number is negative" << std::endl;
    } else {
        std::cout << "The condition  is not performed" << std::endl;
    }
//только одно число кратно 5
    if ((fmod(x, 5) == 0) && (fmod(y, 5) != 0) && (fmod(z, 5) != 0)){
        std::cout << "only one number is a multiple of 5" << std::endl;
    } else {
        if ((fmod(y, 5) == 0) && (fmod(z, 5) != 0) && (fmod(x, 5) != 0)){
            std::cout << "only one number is a multiple of 5" << std::endl;
        } else {
            if ((fmod(z, 5) == 0) && (fmod(y, 5) != 0) && (fmod(x, 5) != 0)){
                std::cout << "only one number is a multiple of 5" << std::endl;
            } else {
                std::cout << "The condition  is not executed" << std::endl;
            }
        }
    }
//Хотя бы одно из чисел больше 100
    if ((x >= 100) || (y >= 0) || (z >= 100)){
        std::cout << "at least one of the numbers is greater than 100" << std::endl;
    } else {
        std::cout << "The condition not executed" << std::endl;
        }
//На поле (a, b) расположена ладья. Записать условие, при котором она угрожает полю (c, d).
    std::pair<int, int> p1;
    int a = 0;
    std::cin >> a;
    p1.first = a;
    int b = 0;
    std::cin >> b;
    p1.second = b;
    int c = 0;
    std::pair<int, int> p2;
    std::cin >> c;
    p2.first = c;
    int d = 0;
    std::cin >> d;
    p2.second = d;
    if ((p1.first == p2.first) || (p1.second == p2.second)){
        std::cout << "The threat from the rook" << std::endl;
    } else {
        std::cout << "There is no threat from the rook" << std::endl;
    }
//На поле (a, b) расположен слон. Записать условие, при котором он угрожает полю (c, d).
    unsigned int y1 = 1;
    int k = 0;
    bool condition1 = false;
    for (unsigned int x1 = 1; x1 <= 8; ++x1){
        condition1 = (p1.first + x1 == p2.first) && (p1.second + y1== p2.second);
        if (condition1 == true){ ++k;
        } else {
            if ((p1.first - x1 == p2.first) && (p1.second - y1== p2.second)){ k++;
            }} y1++;}
    if (k > 0){
        std::cout << "The threat from the bishop" << std::endl;
    } else {
        std::cout << "There is no threat from the bishop" << std::endl;
    }
//На поле (a, b) расположен король.
    //Записать условие, при котором он может одним ходом попасть на поле (c, d).
    condition1 = (p1.first + 1 == p2.first) && (p2.second == p2.second);
    bool condition2 = (p1.first - 1 == p2.first) && (p1.second == p2.second);
    bool condition3 = (p1.second == p2.second - 1) && (p1.first == p2.first);
    bool condition4 = (p1.first == p2.first) && (p1.second == p2.second + 1);
    bool condition5 = (p1.first + 1 == p2.first) && (p1.second == p2.second);
    bool condition6 = (p1.first - 1 == p2.first) && (p1.second - 1 == p2.second);
    if (condition1 || condition2 || condition3 || condition4 || condition5 || condition6){
        std::cout << "Danger" << std::endl;
    } else {
            std::cout << "Out Of Danger" << std::endl;
        }
    }
// На поле (a, b) расположен ферзь. Записать условие, при котором он угрожает полю (c, d).
   unsigned int y1 = 1;
    for (unsigned int x1 = 1; x1 <= 8; ++x1;){
        condition1 = (p.first + x1 == p2.first) && (p.second + y1== p2.second);
        condition2 = (p.first - x1 == p2.first) && (p.second - y1== p2.second);
        ++y1;
        if (condition1 || condition2){ ++k;
        }
    }
    if ((k > 0) || (p1.first == p2.first) || (p1.second == p2.second)){
        std::cout << "The queen from the bishop" << std::endl;
    } else {
        std::cout << "There is no threat from the queen" << std::endl;
    }
// На поле (a, b) расположена белая пешка. Записать условие,
    //при котором она может одним ходом попасть на поле (c, d):при обычном ходе;
    if (p.second == d + 1){
        std::cout << "Danger" << std::endl;
    } else {
        std::cout << "Out Of Danger" << std::endl;
    }
// На поле (a, b) расположена белая пешка. Записать условие, при котором она может
    //одним ходом попасть на поле (c, d):когда она "бьет" фигуру или пешку соперника.
    if (((p.first + 1 == c) && (p.second + 1 == d)) || ((p.first - 1 = c) && (p.second + 1 == d))){
        std::cout << "Danger of the pawn" << std::endl;
    } else {
        std::cout << "Out Of Danger of the pawn" << std::endl;
    }
//Напечатать таблицу умножения на 7:
    for (unsigned int i = 1; i <= 9; ++i){
        std::cout << i << "*" << "7" << "=" << i * 7 << std::endl;
    }
//произведение всех целых чисел от 8 до 15
    for (unsigned int u = 8; u <= 15; ++u){
        for (unsigned int i = 8; i <= 15; ++i){
            std::cout << i << "*" << u << "=" << i * u << std::endl;
        }
// или
    int composition = 1;
    for (u = 8;; u <= 15; ++u){
        composition = composition * u;
    }
//произведение всех целых чисел от a до 20 (значение a вводится с клавиатуры; 1 < a < 20)
    std::cout << "Введите число" << std::endl;
    int a = 0;
    std::cin >> a;
    for (unsigned int u = a; u < 20; ++u){
        for (unsigned int i = a; u <= 20; ++i){
            std::cout << i << "*" << u << "=" << i * u << std::endl;
        }
    }
    std::cout << "Composition =" << composition << std::endl;
// или
    int composition = 1;
    for (u = a ; u < 20; ++u){
        composition = composition * u;
    }
    std::cout << "Composition =" << composition << std::endl;
//произведение всех целых чисел от 1 до b (значение b вводится с клавиатуры; 1 < b < 20)
    std::cout << "Введите число" << std::endl;
    int b = 0;
    std::cin >> b;
    for (unsigned int u = 1; u < b; ++u){
        for (unsigned int i = 1; i < b; ++i){
            std::cout << i << "*" << u << "=" << i * u << std::endl;
        }
    }
// или
    composition = 1;
    for (u = 1 ; u < b; ++u){
        composition = composition * u;
    }
    std::cout << "Composition =" << composition << std::endl;
//произведение всех целых чисел от a до b (значения a и b вводятся с клавиатуры; b >= a)
    for (unsigned int u = a; u < b; ++u){
        for (unsigned int i = a; i < b; ++i){
            std::cout << i << "*" << u << "=" << i * u << std::endl;
        }
    }
// или
    composition = 1;
    for (u = a ; u < b; ++u){
        composition = composition * u;
    }
    std::cout << "Composition =" << composition << std::endl;
    return 0;
}
