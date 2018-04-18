#include <iostream>
#include"findpath.hpp"

int main() {
    unsigned char map[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1};
    int outBuffer[12] = {0};
    int x = findPath(0, 0, 1, 2, map, 4, 3, outBuffer, 12);
    std::cout << x << std::endl;
    for (size_t i = 0; i < 12; ++i)
        std::cout << outBuffer[i] << " ";
    unsigned char map1[] = {0, 0, 1, 0, 1, 1, 1, 0, 1};
    int x1 = findPath(2, 0, 0, 2, map1, 3, 3, outBuffer, 7);
    std::cout << x1 << std::endl;
    return 0;
}
