#include <iostream>
#include <fstream>
#include <vector>

int getHighestInd(std::vector<int> &vec_int) {
    int highest = 0;

    for (unsigned int i = 0; i < vec_int.size(); ++i) {
        if (vec_int[i] > vec_int[highest]) {
            highest = i;
        }
    }
    return highest;
}

int isDup(std::vector<std::vector<int>> &vec, std::vector<int> &newest) {

    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == newest) {
            return ((int)vec.size() - i);
        }
    }
    return -1;
}

void part1(std::vector<int> &vec_int) {
    std::vector<std::vector<int>> vec;
    unsigned int steps = 0;

    while (true) {
        ++steps;
        int highest = getHighestInd(vec_int);
        int val = vec_int[highest];
        vec_int[highest] = 0;

        for (int i = (highest + 1); i < (highest + val + 1); ++i) {
            ++vec_int[i % vec_int.size()];
        }
        int ret = isDup(vec, vec_int);
        if (ret != -1) {
            std::cout << "Part 1: " << steps << std::endl;
            std::cout << "Part 2: " << ret << std::endl;
            return;
        }

        vec.push_back(vec_int);
    }
}

int main(int argc, char *argv[]) {

    std::fstream input_file(argv[1], std::ios_base::in);
    std::vector<int> vec_int;

    int input;

    while (input_file >> input) {
        vec_int.push_back(input);
    }

    part1(vec_int);

    return 0;
}