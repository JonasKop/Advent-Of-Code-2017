#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[]) {

    std::string input;
    std::ifstream input_file(argv[1]);
    std::vector<std::string> input_vec;
    int checksum = 0;

    if (input_file.is_open()) {
        while (std::getline(input_file, input)) {
            input_vec.push_back(input);
        }
        input_file.close();
    } else {
        std::cout << "Unable to open file\n";
        exit(1);
    }

    for (unsigned int i = 0; i < input_vec.size(); ++i) {
        std::vector<int> row;
        std::string str = input_vec.at(i);

        unsigned int start = 0;
        unsigned int end = 0;
        for (unsigned int j = 1; j < str.size(); ++j) {

            if ((str.at(j) == ' ' && str.at(j - 1) != ' ') || (str.at(j) == '\t' && str.at(j - 1) != '\t')) {
                end = j;
                std::string nr = str.substr(start, end - start);
                row.push_back(std::stoi(nr));
            } else if ((str.at(j) != ' ' && str.at(j - 1) == ' ') || (str.at(j) != '\t' && str.at(j - 1) == '\t')) {

                start = j;
            }

            if ((str.at(j) != ' ' && j == (str.size() - 1)) || (str.at(j) != '\t' && j == (str.size() - 1))) {
                end = j;
                std::string nr = str.substr(start, end - start + 1);
                row.push_back(std::stoi(nr));
            }
        }

        int lowest = row.at(0);
        int highest = row.at(0);
        for (unsigned int k = 1; k < row.size(); ++k) {
            if (row.at(k) < lowest) {
                lowest = row.at(k);
            } else if (row.at(k) > highest) {
                highest = row.at(k);
            }
        }
        checksum += highest - lowest;
    }

    std::cout << checksum;

    return 0;
}