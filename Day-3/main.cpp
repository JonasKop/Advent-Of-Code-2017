#include <iostream>
#include <vector>


int getLength(int size, int maxnr) {
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

int near(std::vector<std::vector<int>> vec, int x, int y) {

    int sum = 0;

    for (int i = -1; i < 2; ++i) {
        sum += vec[x + i][y - 1];
        sum += vec[x + i][y + 1];
    }
    sum += vec[x - 1][y];
    sum += vec[x + 1][y];

    return sum;
}

int getstrangelength(int maxnr){
    int size = 15;
    int x = size / 2;
    int y = x;
    std::vector<std::vector<int>> vec;
    int val = 1;
    int length = 1;


    for (int i = 0; i < size; ++i) {
        std::vector<int> v;
        for (int j = 0; j < size; ++j) {
            v.push_back(0);
        }
        vec.push_back(v);
    }

    vec[x][y] = val;
    int i = 1;
    while (i < (13 * 13)) {

        ++x;
        ++i;
        vec[x][y] = near(vec, x, y);
        int temp_y;
        int temp_x;

        temp_y = y;
        while (y > temp_y - length) {
            --y;
            ++i;
            vec[x][y] = near(vec, x, y);
            if (vec[x][y] > maxnr) {
                return vec[x][y];
            }
        }

        ++length;
        temp_x = x;
        while (x > temp_x - length) {
            --x;
            ++i;
            vec[x][y] = near(vec, x, y);
            if (vec[x][y] > maxnr) {
                return vec[x][y];
            }
        }

        temp_y = y;
        while (y < temp_y + length) {
            ++y;
            ++i;
            vec[x][y] = near(vec, x, y);
            if (vec[x][y] > maxnr) {
                return vec[x][y];
            }
        }

        temp_x = x;
        while (x < temp_x + length) {
            ++x;
            ++i;
            vec[x][y] = near(vec, x, y);
            if (vec[x][y] > maxnr) {
                return vec[x][y];
            }
        }
        ++length;
    }
    return 0;
}

int main(int argc, char *argv[]) {

    if (argv[1] == nullptr) {
        std::cout << "Missing argument" << std::endl;
        exit(1);
    }

    int maxnr = std::stoi(argv[1]);
    int size;

    for (size = 1; size * size < maxnr; size += 2);

    std::cout << "Part 1: " << getLength(size, maxnr) << std::endl;
    std::cout << "Part 2: " << getstrangelength(maxnr) << std::endl;

    return 0;
}