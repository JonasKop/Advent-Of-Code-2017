#include <iostream>
#include <fstream>
#include <vector>

int part1(std::vector<int> vec) {

    unsigned int i = 0;
    int jumps = 0;

    while (true) {
        try {
            i += vec.at(i)++;
        } catch (...) {
            return jumps;
        }
        ++jumps;
    }
}

int part2(std::vector<int> vec) {
    unsigned int i = 0;
    int jumps = 0;

    while (true) {
        try {
            i += (vec.at(i) >= 3 ? vec.at(i)-- : vec.at(i)++);
        } catch (...) {
            return jumps;
        }
        ++jumps;
    }
}

int main(int argc, char *argv[]) {

    std::fstream input_file(argv[1], std::ios_base::in);
    std::vector<int> vec_int;

    int input;
    while (input_file >> input) {
        vec_int.push_back(input);
    }

    int p1 = part1(vec_int);
    int p2 = part2(vec_int);

    std::cout << "p1: " << p1 << std::endl;
    std::cout << "p2: " << p2 << std::endl;

    return 0;
}