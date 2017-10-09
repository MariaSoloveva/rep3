#include <algorithm>
#include <iostream>
#include <cmath>
#include <random>
#include <string>
#include <vector>

template<class T>
std::vector<T> generate_random_vector(std::size_t num, T min = -10, T max = 20)
{
    std::random_device rd;
    std::mt19937 e2(rd());
    std::uniform_real_distribution<T> dist(min, max);

    auto lambda = [&e2, &dist] () { return dist(e2); };

    std::vector<T> result(num);
    std::generate_n(result.begin(), num, lambda);
    return result;
}

int main() {
// Все элементы увеличить в 2 раза;уменьшить на число a;разделить на первый элемент
    std::vector<double> v = generate_random_vector<double>(10, -10, 10);
    std::cout << "Enter a number" << std::endl;
    int a = 0;
    std::cin >> a;
    for (int i = 0; i < 10; ++i) {
        v[i] = 2 * v[i];
        std::cout << v[i] << " ";
    }
    for (int i = 0; i < 10; ++i) {
        v[i] = v[i] - a;
        std::cout << v[i] << " ";
    }
    a = v[0];
    for (int i = 0; i < 10; ++i) {
        v[i] = v[i] / a;
        std::cout << v[i] << " ";
    }
/* Определить сумму всех элементов массива;сумму квадратов всех элементов массива;
    сумму шести первых элементов массива;сумму элементов массива с k1-го по k2й (значения k1 и k2 вводятся с клавиатуры; k2 > k1);
        среднее арифметическое всех элементов массива;
            среднее арифметическое элементов массива с s1-го по s2-й (значения s1 вводятся с клавиатуры; s2 > s1)*/
    std::vector<int> v1 = generate_random_vector<int>(10, -10, 10);
    int sumAll = 0;
    int sumSquare = 0;
    int sumFirstSix = 0;
    std::cout << "Enter k1 and k2 , k2 > k1" <<std::endl;
    int k1 = 0;
    std::cin >> k1;
    int k2 = 0;
    std::cin >> k2;
    int sumK1ToK2 = 0;
    std::cout << "Enter s1 and s2 , s2 > s1" <<std::endl;
    int s1 = 0;
    std::cin >> s1;
    int s2 = 0;
    std::cin >> s2;
    int sums1Tos2 = 0;
    for (int i = 0; i < v1.size(); ++i) {
        sumAll = sumAll + v[i];
        sumSquare = sumSquare + v[i] * v[i];
        if (i <= 6) {
            sumFirstSix = sumFirstSix + v1[i];
        }
        if ((i >= k1) && (k2 >= i)) {
            sumK1ToK2 = sumK1ToK2 + v1[i];
        }
        if ((i >= s1) && (s2 >= i)) {
            sums1Tos2 = sums1Tos2 + v1[i];
        }
    }
    double average = sumAll / v1.size();
    double averages1Tos2 = sums1Tos2 / (s2 -s1 + 1);
    std::cout << "Summ of all elements is " << sumAll << std::endl;
    std::cout << "Summ of square elements is " << sumSquare << std::endl;
    std::cout << "Summ of first six elements is " << sumFirstSix << std::endl;
    std::cout << "Summ of elements from k1 to k2 is " << sumK1ToK2 << std::endl;
    std::cout << "Average of all elements is " << average << std::endl;
    std::cout << "Average of elements from s1 to s2 is " <<averages1Tos2 << std::endl;
/*Дан одномерный массив из 20 элементов. Переставить первые три и последние три элемента,
    сохранив порядок их следования. */
    std::vector<int> v2 = generate_random_vector<int>(20, -10, 10);
    for (int i = 0; i < v2.size(); ++i) {
        std::cout << v[i] << " ";
    }
    k2 = 0;
    for (int i = 3; i > 0; --i){
        k1 = v2[k2];
        v2[k2] = v2[v2.size() - i];
        v2[v2.size() - i] = k1;
        k2 += 1;
    }
    for (int i = 0; i < v2.size(); ++i) {
        std::cout << v[i] << " ";
    }
// Удалить первый отрицательный элемент (если отрицательные элементы в массиве есть);
    std::vector<int> v3 = generate_random_vector<int>(20, -10, 10);
    int n = 0;
    int m = 0;
    while (n = 0) {
        if (v3[m] < 0) {
            n += 1;
        }
        m += 1;
    }
    for (int i = m; i < (v3.size() - 1); ++i){
       v3[i] = v3[i + 1];
    }
    v3.erase(v3.end());
// Удалить последний четный элемент (если четные элементы в массиве есть).
    n = 0;
    m = v3.size();
    while (n = 0) {
        if (v3[m] % 2 == 0) {
            n += 1;
        }
        m -= 1;
    }
    for (int i = m; i < (v3.size() - 1); ++i){
       v3[i] = v3[i + 1];
    }
    v3.erase(v3.end());
//Дано название города. Определить, четно или нет количество символов в нем.
    std::cout << "Enter the name of the city" << std::endl;
    std::string nameOfTheCity;
    getline(std::cin, nameOfTheCity);
    int len = nameOfTheCity.size();
    if (nameOfTheCity.find(" ") > 0) {
        len = len - 1;
    }
    if (len % 2 == 0) {
        std::cout << "the number of digits is even" << std::endl;
    } else {
            std::cout << "the number of digits is odd" << std::endl;
    }
//Даны две фамилии. Определить, какая из них длиннее
    std::cout << "Enter first and second surname" << std::endl;
    std::string surname1;
    std::cin >> surname1;
    std::string surname2;
    std::cin >> surname2;
    if (surname1.size() > surname2.size()) {
        std::cout << surname1 << " is longer" << std::endl;
    } else {
        std::cout << surname2 << " is longer" << std::endl;
    }
//Даны названия трех городов. Вывести на экран самое длинное и самое короткое название.
    std::cout << "Enter surnames" << std::endl;
    getline(std::cin, surname1);
    getline(std::cin, surname2);
    std::string surname3;
    getline(std::cin, surname3);
    if ((surname1.size() > surname2.size()) && (surname2.size() > surname3.size())) {
        std::cout << "The longest is " << surname1 << std::endl;
        std::cout << "The shortest is " << surname3 << std::endl;
    } else {
        if ((surname1.size() > surname3.size()) && (surname3.size() > surname2.size())) {
            std::cout << "The longest is " << surname1 << std::endl;
            std::cout << " and the shortest is " << surname2 << std::endl;
        } else {
            if ((surname2.size() > surname1.size()) && (surname1.size() > surname3.size())) {
                std::cout << "The longest is " << surname2 <<std::endl;
                std::cout << "The shortest is " << surname3 << std::endl;
            } else {
                if ((surname2.size() > surname3.size()) && (surname3.size() > surname1.size())) {
                    std::cout << "The longest is " << surname2 << std::endl;
                    std::cout << " The shortest is " << surname1 << std::endl;
                } else {
                    if ((surname3.size() > surname1.size()) &&
                        (surname1.size() > surname2.size())) {
                        std::cout << "The longest is " << surname3 << std::endl;
                        std::cout << " and the shortest is " << surname2 << std::endl;
                    } else {
                        std::cout << "The longest is " << surname3 << std::endl;
                        std::cout << " The shortest is " << surname1 << std::endl;
                    }
                }
            }
        }
    }
// Дано слово. Получить его часть, образованную идущими подряд буквами, начиная с m-й и кончая n-й.
    std::cout << "Enter a word" << std::endl;
    std::string word;
    std::cin >> word;
    std::cout << "Enter the first character of the copy and past" << std::endl;
    n = 0;
    std::cin >> n;
    m = 0;
    std::cin >> m;
    char buffer[20];
    std::size_t length = word.copy(buffer, m - n + 1, n);
    buffer[length]='\0';
    std::cout << buffer << '\n';
// Дано слово. Добавить к нему в начале и конце столько звездочек, сколько букв в этом слове.
    std::cout << "Enter a word" << std::endl;
    std::string str1;
    std::cin >> str1;
    unsigned int len1 =  str1.size();
    for (unsigned int i =0; i < len1; ++i) {
      str1.insert(0, "*");
      str1.push_back('*');
    }
    std::cout << str1 << std::endl;
// Дано предложение. Определить долю (в %) букв 'a' в нем.
    std::cout << "Enter a proposition" << std::endl;
    std::string proposition;
    n = 0;
    getline(std::cin, proposition);
    m = proposition.find("a");
    while (m > 0) {
        proposition.erase(0, m);
        ++n;
        m = proposition.find("a");
    }
    double percentage = (n / proposition.size()) * 100;
    std::cout << percentage << " %" << std::endl;
/* Дано предложение "Can you can a can as a canner can can a can?".
    Заменить все слова can на слово newWord */
    std::string str = "Can you can a can as a canner can can a can?";
    std::cout << "Enter a word" << std::endl;
    std::string newWord;
    std::cin >> newWord;
    str.insert(str.size() - 1, " ");
    n = str.find(" can ");
    while (n >= 0) {
        str.replace(n + 1, 3, newWord);
        n = str.find(" can ");
    }
    str.erase(str.size() - 2, 1);
    std::cout << str << std::endl;
    return 0;
}
