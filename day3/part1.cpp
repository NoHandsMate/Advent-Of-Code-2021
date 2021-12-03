#include <string>
#include <bitset>
#include <fstream>
#include <vector>
#include <iostream>

constexpr unsigned int BIT_NUMBER = 5;


auto getInput(const std::string& path) {
    
    auto file = std::fstream(path);
    
    std::string temp{};
    std::vector<std::bitset<BIT_NUMBER>> input;
    
    while(std::getline(file, temp)) {
        std::bitset<BIT_NUMBER> bit {temp};
        input.push_back(bit);
    }

    file.close();
    return input;
}

template<typename T>
auto calc_gamma_rate(const T& input) {
    
    std::bitset<BIT_NUMBER> temp_bit;
    size_t index      {0};
    size_t one_count  {0};
    size_t zero_count {0};

    while (index < BIT_NUMBER) {

        for(const auto& number : input) {
            if(number.test(index)) {
                one_count++;
            } else {
                zero_count++;
            }
        }

        if(one_count > zero_count) {
            temp_bit[index] = 1;
        } else {
            temp_bit[index] = 0;
        }

        one_count = 0;
        zero_count = 0;
        index++;
    }

    return temp_bit.to_ulong();
}

template<typename T>
auto calc_epsilon_rate(const T& input) {
    
    std::bitset<BIT_NUMBER> temp_bit;
    size_t index      {0};
    size_t one_count  {0};
    size_t zero_count {0};

    while (index < BIT_NUMBER) {

        for(const auto& number : input) {
            if(number.test(index)) {
                one_count++;
            } else {
                zero_count++;
            }
        }

        if(one_count > zero_count) {
            temp_bit[index] = 0;
        } else {
            temp_bit[index] = 1;
        }

        one_count = 0;
        zero_count = 0;
        index++;
    }

    return temp_bit.to_ulong();
}


template<typename T>
auto part1(const T& input) {

    auto gamma_rate = calc_gamma_rate(input);
    auto epsilon_rate = calc_epsilon_rate(input);
    return gamma_rate * epsilon_rate;

}


auto main() -> int {

    auto input = getInput("input.txt");
    auto ans1 = part1(input);
    std::cout << "ANS1 : " << ans1;
    
}