#include <iostream>

int getlength(int size, int maxnr) {
    int length = 1;
    int i = 1;
    int x = size / 2;
    int y = x;

    while (true) {
        ++x;
        ++i;
        int temp_y;
        int temp_x;

        temp_y = y;
        while (y > temp_y - length) {
            --y;
            ++i;
            if (i == maxnr) {
                return abs(x - size / 2) + abs(y - size / 2);
            }
        }

        ++length;
        temp_x = x;
        while (x > temp_x - length) {
            --x;
            ++i;
            if (i == maxnr) {
                return abs(x - size / 2) + abs(y - size / 2);
            }
        }

        temp_y = y;
        while (y < temp_y + length) {
            ++y;
            ++i;
            if (i == maxnr) {
                return abs(x - size / 2) + abs(y - size / 2);
            }
        }

        temp_x = x;
        while (x < temp_x + length) {
            ++x;
            ++i;
            if (i == maxnr) {
                return abs(x - size / 2) + abs(y - size / 2);
            }
        }
        ++length;
    }
}

int main(int argc, char *argv[]) {

    if (argv[1] == nullptr) {
        std::cout << "Missing argument" << std::endl;
        exit(1);
    }

    int maxnr = std::stoi(argv[1]);
    int size;

    for (size = 1; size * size < maxnr; size += 2);

    std::cout << getlength(size, maxnr) << std::endl;
    
    return 0;
}