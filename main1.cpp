#include <iostream>

int findPath(const int startX, const int startY,
                 const int targetX, const int targetY,
                 const unsigned char* map, const int mapWidth, const int mapHeight,
                 int* outBuffer, const int outBufferSize)
    {
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        bool stop;
        unsigned char** mapTabl = new unsigned char*[mapHeight];
        for (int i = 0; i < mapHeight; ++i)
        {
            mapTabl[i] = new unsigned char[mapWidth];
            for (int j = 0; j < mapWidth; ++j)
                if (map[mapWidth * i + j] == (unsigned char)(0))
                    mapTabl[i][j] = (unsigned char)(-1);
                else
                    mapTabl[i][j] = (unsigned char)(-2);
        }
        if (mapTabl[targetY][targetX] == (unsigned char)(-1) ||
            mapTabl[startY][startX] == (unsigned char)(-1))
            return -1;
        unsigned char d = 0;
        mapTabl[startY][startX] = 0;
        do
        {
            stop = true;
            for (int y = 0; y < mapHeight; ++y)
                for (int x = 0; x < mapWidth; ++x)
                    if (mapTabl[y][x] == d)
                    {
                        for (int k = 0; k < 4; ++k)
                        {
                            int iy = y + dy[k];
                            int ix = x + dx[k];
                            if (iy >= 0 && iy < mapHeight && ix >= 0 && ix < mapWidth &&
                                    mapTabl[iy][ix] == (unsigned char)(-2))
                            {
                                stop = false;
                                mapTabl[iy][ix] = (unsigned char)(d + 1);
                            }
                        }
                    }
            d++;
        } while (!stop && mapTabl[targetY][targetX] == (unsigned char)(-2));
        outBuffer[mapTabl[targetY][targetX] - 1] = targetX + targetY * mapWidth;
        d = mapTabl[targetY][targetX];
        int x = targetX;
        int y = targetY;
        while (d > 0)
        {
            --d;
            /*for (int k = 0; k < 4; ++k)
            {
                int y1 = y + dy[k];
                int x1 = x + dx[k];
                if (y1 >= 0 && y1 < mapHeight && x1 >= 0 && x1 < mapWidth && mapTabl[y1][x1] == d)
                {
                    x = x + dx[k];
                    y = y + dy[k];
                    break;
                }
            }*/
            outBuffer[mapTabl[y][x] - 1] = x + y * mapWidth;
        }
        //  x = mapTabl[targetY][targetX];
        for (int i = 0; i < mapHeight; ++i)
        {
            delete[] mapTabl[i];
        }
        delete[] mapTabl;
        return 1;
    }

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
