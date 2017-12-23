#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::vector<std::string> split_by_space(std::string str) {
    std::vector<std::string> vec_str;
    std::size_t pos = 0, found;
    while((found = str.find_first_of(' ', pos)) != std::string::npos) {
        std::string s = str.substr(pos, found - pos);
        if (!s.empty()){
            vec_str.push_back(s);
        }
        pos = found + 1;
    }
    vec_str.push_back(str.substr(pos));
    return vec_str;
}

bool part1(std::string str) {
    std::vector<std::string> vec_str = split_by_space(str);

    int i = 0;
    for (const std::string s : vec_str) {
        int j = 0;
        for (const std::string s1 : vec_str) {
            if (j != i && s1 == s) {
                return false;
            }
            j++;
        }
        ++i;
    }
    return true;
}

bool part2(std::string str) {

    std::vector<std::string> vec_str = split_by_space(str);

    for (unsigned int i = 0; i < vec_str.size(); i++) {
        for (int j = 0; j < vec_str.size(); ++j) {
            if (i != j && vec_str[j].length() == vec_str[i].length()) {
                std::sort(vec_str[j].begin(), vec_str[j].end());
                std::sort(vec_str[i].begin(), vec_str[i].end());
                if (vec_str[j] == vec_str[i]) {
                    return false;
                }
            }
        }
    }
    return true;
}


int main(int argc, char *argv[]) {

    std::vector<std::string> vec;
    std::string input;
    std::ifstream input_file(argv[1]);

    if (input_file.is_open()) {

        while (getline(input_file, input)) {
            vec.push_back(input);
        }

        input_file.close();
    } else {
        std::cout << "Unable to open file\n";
        exit(1);
    }

    int part1_sum = 0;
    int part2_sum = 0;

    for (const std::string str : vec) {
        if (part1(str)) {
            ++part1_sum;
        }
        if (part2(str)) {
            ++part2_sum;
        }
    }

    std::cout << "Part 1: " << part1_sum << std::endl;
    std::cout << "Part 2: " << part2_sum << std::endl;
    return 0;
}