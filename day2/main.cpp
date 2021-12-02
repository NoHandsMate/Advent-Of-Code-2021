#include <iostream>
#include <string>
#include <fstream>

auto main() -> int {

    size_t depth {};
    size_t horizontal{};

    std::fstream file("input.txt");

    std::string line {};

    while(std::getline(file, line)) {

        if(line.starts_with("forward")) {
            auto value = std::stoi(line);
            horizontal += value;
        }

    }

}