#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <bitset>
#include <iostream>

using uint = unsigned int;

constexpr uint BIT_NUMBER = 12;

auto get_input_file(const std::string& path) -> std::vector<std::string> {
    auto file = std::fstream(path);
    
    std::string temp {};
    std::vector<std::string> out;

    while(std::getline(file, temp)) {
        temp.erase(std::remove(temp.begin(), temp.end(), '\n'), temp.end());
        out.push_back(temp);
    }

    return out;
}


auto rating_calc(std::vector<std::string>& input, bool is_co2) {

    uint one_count  {0};
    uint zero_count {0};
    uint index {0};

    while(index < BIT_NUMBER) {
        
        if(input.size() == 1) {
            break;
        }

        for(const auto& string : input) {
            if(string[index] == '1') {
                one_count++;
            } else {
                zero_count++;
            }
        }
        
        if(!is_co2) {
            if(one_count > zero_count || one_count == zero_count) {
                input.erase(std::remove_if(input.begin(), input.end(), [&](const auto& number) {
                        return number[index] == '0';
                    }), input.end());
            } else {
                input.erase(std::remove_if(input.begin(), input.end(), [&](const auto& number) {
                        return number[index] == '1';
                    }), input.end());
            }
        } else {
            if(one_count > zero_count || one_count == zero_count) {
            input.erase(std::remove_if(input.begin(), input.end(), [&](const auto& number) {
                    return number[index] == '1';
                }), input.end());
            } else {
            input.erase(std::remove_if(input.begin(), input.end(), [&](const auto& number) {
                    return number[index] == '0';
                }), input.end());
            }
        }

        one_count = 0;
        zero_count = 0;
        index++;
    }

    std::bitset<BIT_NUMBER> bitfied {input[0]};
    return bitfied.to_ulong();

}

auto part2(std::vector<std::string>& input) {
    
    auto copied_input = input;
    auto oxigen = rating_calc(input, false);
    auto co2_calc = rating_calc(copied_input, true);
    
    return oxigen * co2_calc;
}

auto main() -> int {

    auto input = get_input_file("input.txt");
    auto ans = part2(input);

    std::cout << "ANS: " << ans;
}