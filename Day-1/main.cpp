#include <iostream>
#include <fstream>

char next(std::string str, unsigned int index, unsigned int dist) {
    unsigned long new_ind = index + dist;
    new_ind = new_ind % str.size();
    return str.at(new_ind);
}

int next_is_same(std::string str, unsigned int index, unsigned int dist) {
    if (next(str, index, dist) == str.at(index)) {
        return (str.at(index) - '0');
    }
    return 0;
}

int main(int argc, char *argv[]) {

    std::string input;
    std::ifstream input_file(argv[1]);

    if (input_file.is_open()) {
        getline(input_file, input);
        input_file.close();
    } else {
        std::cout << "Unable to open file\n";
        exit(1);
    }

    unsigned int sumnext = 0;
    unsigned int sumhalf = 0;
    for (unsigned int i = 0; i < input.size(); ++i) {
        sumnext += next_is_same(input, i, 1);
        sumhalf += next_is_same(input, i, (unsigned int) input.size() / 2);
    }

    std::cout << "sumnext: " << sumnext << std::endl;
    std::cout << "sumhalf: " << sumhalf << std::endl;

    return 0;
}