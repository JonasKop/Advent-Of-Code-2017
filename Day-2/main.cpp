#include <iostream>
#include <fstream>
#include <vector>

bool isSpaceOrTab(char c) {
    return (c == ' ' || c == '\t');
}

int main(int argc, char *argv[]) {

    std::string input;
    std::ifstream input_file(argv[1]);
    std::vector<std::string> input_vec;
    int checksum = 0;
    int strangechecksum = 0;

    if (input_file.is_open()) {
        while (std::getline(input_file, input)) {
            input_vec.push_back(input);
        }
        input_file.close();
    } else {
        std::cout << "Unable to open file\n";
        exit(1);
    }
    for (std::string str : input_vec) {
        std::vector<int> row;
        unsigned int start = 0;
        unsigned int end = 0;

        for (unsigned int j = 1; j < str.size(); ++j) {

            if (isSpaceOrTab(str.at(j)) && !isSpaceOrTab(str.at(j - 1))) {
                end = j;
                std::string nr = str.substr(start, end - start);
                row.push_back(std::stoi(nr));
            } else if (!isSpaceOrTab(str.at(j)) && isSpaceOrTab(str.at(j - 1))) {
                start = j;
            }

            if (!isSpaceOrTab(j) && j == str.size() - 1) {
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


        for (int j = 0; j < row.size(); ++j) {
            for (int k = 0; k < row.size(); ++k) {
                if (j != k) {
                    if (row[k] % row[j] == 0) {
                        strangechecksum += (row[k] / row[j]);
                    }
                }
            }

        }
    }

    std::cout << "Checksum: " << checksum << std::endl;
    std::cout << "Strange checksum: " << strangechecksum << std::endl;

    return 0;
}