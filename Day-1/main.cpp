#include <iostream>
#include <fstream>

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

    int sum = 0;
    for (unsigned int i = 0; i < input.size() - 1; ++i) {

        int c0 = input.at(i) - '0';
        int c1 = input.at(i + 1) - '0';
		
		if (!(c0 < 10 && c0 >= 0 && c1 < 10 && c1 >= 0)){
			std::cout << "char nr: " << i << " NaN" << std::endl;
			exit(1);
		}

        if (c0 == c1) {
            sum += c0;
        }
    }

    if (input.at(input.size() - 1) == input.at(0)) {
        int c0 = input.at(input.size() - 1) - 48;
        int c1 = input.at(0) - 48;

		if (!(c0 < 10 && c0 >= 0 && c1 < 10 && c1 >= 0)){
			std::cout << "char nr: " << i << " NaN" << std::endl;
			exit(1);
		}

        if (c0 == c1) {
            sum += c0;
        }
    }

    std::cout << sum << std::endl;
    return 0;
}
