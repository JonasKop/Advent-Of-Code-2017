#include <iostream>
#include <vector>
#include <fstream>

struct node {
    std::string name;
    int weight;
    std::string children;
};

struct real_node {
    std::string name;
    int weight;
    std::vector<real_node> children;
};

bool isChild(std::vector<node> parents, unsigned long index) {

    node active_node = parents.at(index);
    for (node &in : parents) {
        if (in.children.find(active_node.name) != std::string::npos) {
            return true;
        }
    }

    return false;
}



void part1(std::vector<std::string> vec) {
    std::vector<node> parents;
    std::vector<node> children;

    for (std::string &str : vec) {
        unsigned long index;
        if ((index = (int) str.find('-')) != std::string::npos) {
            node n;
            n.children = str.substr(index + 3);

            index = (int) str.find(' ');
            n.name = str.substr(0, index);

            unsigned long endind = str.find(')') - (index += 2);

            n.weight = std::stoi(str.substr(index, endind));
            parents.push_back(n);

        } else {
            node n;

            index = (int) str.find(' ');
            n.name = str.substr(0, index);

            n.weight = std::stoi(str.substr(index + 2));
            parents.push_back(n);
        }
    }

    unsigned long index = 0;
    while (isChild(parents, index)) { ++index; }

    std::cout << "Part 1: " << parents.at(index).name << std::endl;

    real_node root_node;
    root_node.name = parents.at(index).name;
    root_node.weight = parents.at(index).weight;




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

    part1(vec);

    return 0;
}