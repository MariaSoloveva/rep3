#include <cmath>
#include <iostream>

int main () {
    char n = 0;
    do {
        std::cout << "What chess piece?" << std::endl;
        std::cin >> n;
    } while ((n != 'p') && (n != 'N') && (n != 'Q') && (n != 'R') && (n != 'B'));
    std::pair<char, int> firstPair;
    do {
        std::cout << " Initial coordinate? " << std::endl;
        std::cin >> firstPair.first >> firstPair.second;
    } while ((firstPair.second > 8) || ((firstPair.first != 'a') &&
            (firstPair.first != 'b') && (firstPair.first != 'c')
                                        && (firstPair.first != 'd') && (firstPair.first != 'e')
                                        && (firstPair.first != 'f')  && (firstPair.first != 'h')));
    std::pair<char, int> next;
    next.first = 'e';
    next.second = 4;
    do {
        std::cout << " Next coordinate? " << std::endl;
        std::cin >> next.first >> next.second;
    } while ((firstPair.second > 8) || ((firstPair.first != 'a') && (firstPair.first != 'b') && (firstPair.first != 'c')
                                 && (firstPair.first != 'd') && (firstPair.first != 'e') && (firstPair.first != 'f')
                                       && (firstPair.first != 'h')));
    std::cout << "Answer: " << std::endl;
    if (n == 'p') {
        if (((next.first == firstPair.first) && (next.second - 1 == firstPair.second)) &&
                ((next.first != 'f') && (firstPair.second != 7))){
            std::cout << "The figure can move" << std::endl;
        } else if ((firstPair.second == 2) && (next.second - 2 == next.second) && (next.first == firstPair.second)) {
            std::cout << "The figure can move" << std::endl;
        } else {
            std::cout << "The figure can't move" << std::endl;
        }
    }
    if (n == 'R') {
        if ((next.first == firstPair.first) || (next.second == firstPair.second)) {
            if ((firstPair.first == 'f') && (next.first == 'f')) {
                if ((next.second < 7) && (firstPair.second < 7)) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.second > 7) && (firstPair.second > 7)) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.second > 7) && (firstPair.second < 7)) {
                    std::cout << "False" << std::endl;
                }
                if ((next.second < 7) && (firstPair.second > 7)) {
                    std::cout << "The figure can't move" << std::endl;
                }
            }
            if ((firstPair.first == 7) && (next.first == 7)) {
                if ((firstPair.first < 'f') && (next.first < 'f')) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.first > 'f') && (firstPair.first > 'f')) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.first > 'f') && (firstPair.first < 'f')) {
                    std::cout << "The figure can't move" << std::endl;
                }
                if ((next.first < 'f') && (firstPair.first > 'f')) {
                    std::cout << "The figure can't move" << std::endl;
                }
            }
            std::cout << "The figure can move" << std::endl;
        }
        else {
            std::cout << "The figure can't move" << std::endl;
        }
    }
    if (n == 'B') {
        if (abs(firstPair.first - firstPair.first) == abs(next.second - firstPair.second)) {
            if (abs(next.first - 'f') == abs(next.second - 7)) {
                if ((next.second > 7) && (firstPair.second < 7)) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.second < 7) && (firstPair.second < 7)) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.second > 7) && (firstPair.second > 7)) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.second < 7) && (firstPair.second > 7)) {
                    std::cout << "The figure can't move" << std::endl;
                }
            }
            std::cout << "The figure can move" << std::endl;
        }
        else {
            std::cout << "The figure can move" << std::endl;
        }
    }
    if (n == 'Q') {
        if ((abs(firstPair.first - firstPair.first) == abs(next.second - firstPair.second)) ||
            ((next.first == firstPair.first) || (next.second == firstPair.second))) {
            if ((firstPair.first == 'f') && (next.first == 'f')) {
                if ((next.second > 7) && (firstPair.second < 7)) {
                    std::cout << "The figure can't move" << std::endl;
                }
                if ((next.second < 7) && (firstPair.second < 7)) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.second > 7) && (firstPair.second > 7)) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.second < 7) && (firstPair.second > 7)) {
                    std::cout << "The figure can't move" << std::endl;
                }
            }
            if ((firstPair.first == 7) && (next.first == 7)) {
                if ((firstPair.first < 'f') && (next.first < 'f')) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.first > 'f') && (firstPair.first > 'f')) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.first > 'f') && (firstPair.first < 'f')) {
                    std::cout << "The figure can't move" << std::endl;
                }
                if ((next.first < 'f') && (firstPair.first > 'f')) {
                    std::cout << "The figure can't move" << std::endl;
                }
            }
            if (abs(next.first - 'f') == abs(next.second - 7)) {
                if ((next.second > 7) && (firstPair.second < 7)) {
                    std::cout << "The figure can't move" << std::endl;
                }
                if ((next.second < 7) && (firstPair.second < 7)) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.second > 7) && (firstPair.second > 7)) {
                    std::cout << "The figure can move" << std::endl;
                }
                if ((next.second < 7) && (firstPair.second > 7)) {
                    std::cout << "The figure can't move" << std::endl;
                }
            }
            std::cout << "The figure can move" << std::endl;
        }
        else {
            std::cout << "The figure can move" << std::endl;
        }
    }
    return 0;
}
