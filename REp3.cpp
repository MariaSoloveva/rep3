#include <iostream>
#include <string>
#include <math.h>

int main() {
//Дано название города. Определить, четно или нет количество символов в нем.
    std::cout << "Enter the name of the city" << std::endl;
    std::string nameOfTheCity;
    std::cout << "Enter Name of the City" << std::endl;
    getline(std::cin, nameOfTheCity);
    if (nameOfTheCity.size() % 2 == 0) {
        std::cout << "the number of digits is even" << std::endl;
    } else {
        std::cout << "the number of digits is odd" << std::endl;
    }
//Даны две фамилии. Определить, какая из них длиннее
    std::cout << "Enter first and second surname" << std::endl;
    std::string surname1;
    getline(std::cin, surname1);
    std::string surname2;
    getline(std::cin, surname2);
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
    int n = 0;
    std::cin >> n;
    int m = 0;
    std::cin >> m;
    std::string part;
    word.copy(part, n - m + 1, 6);
    std::cout << part << std::endl;
// Дано слово. Добавить к нему в начале и конце столько звездочек, сколько букв в этом слове.
    std::cout << "Enter a word" << std::endl;
    std::cin >> word;
    for (unsigned int i = 1; i <= word.size(); ++i) {
        word.insert(0, "*");
        word.push_back('*');
    }
    std::cout << word << std::endl;
// Дано предложение. Определить долю (в %) букв 'a' в нем.
    std::cout << "Enter a proposition" << std::endl;
    std::string proposition;
    n = 0;
    getline(std::cin, proposition);
    while (proposition.find("a") > 0) {
        proposition.erase(0, proposition.find("a"));
        ++n;
    }
    double percentage = (n / proposition.size()) * 100;
    std::cout << percentage << " %" << std::endl;
// Дано предложение "Can you can a can as a canner can can a can?".
    //Заменить все слова can на слово newWord
    std::string str = "Can you can a can as a canner can can a can?";
    std::cout << "Enter a word" << std::endl;
    std::string newWord;
    while (str.find("can") >= 0) {
        std::cin >> newWord;
        str.replace(str.find("can"), str.find("can") + 3, newWord);
    }
    return 0;
}
