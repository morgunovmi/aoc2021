#include <math.h>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>

#include "solve.hpp"
#include  "util/util.hpp"

namespace daythree {

auto bits_to_int(const std::vector<uint8_t>& bits) -> int {
    int res = 0;
    for (const auto bit : bits) {
        res <<= 1;
        res += bit;
    }
    return res; 
}

auto get_bit_counts(const std::vector<std::string_view>& binary_strs) -> std::vector<uint32_t> {
    const auto len = binary_strs[0].length();
    std::vector<uint32_t> one_counts(len);
    for (const auto & str : binary_strs) {
        for (size_t i = 0; i < len; ++i) {
            one_counts[i] += str[i] - '0';
        }
    }
    return one_counts;
}

auto str_to_num_bits(const std::string_view str) -> std::vector<uint8_t> {
    std::vector<uint8_t> bits{};
    std::transform(str.begin(), str.end(), std::back_inserter(bits),
                   [](auto c){ return c - '0'; });

    return bits;
}

auto part_one(const std::vector<std::string_view>& binary_strs) -> void {
    if (binary_strs.empty()) {
        throw std::runtime_error {"Empty input"};
    }

    const auto one_counts = get_bit_counts(binary_strs);

    std::vector<uint8_t> gamma_bits{}; 
    std::transform(one_counts.begin(), one_counts.end(), std::back_inserter(gamma_bits),
                   [&](auto val) { return val > binary_strs.size() / 2 ? 1 : 0; });

    std::vector<uint8_t> epsilon_bits{}; 
    std::transform(gamma_bits.begin(), gamma_bits.end(), std::back_inserter(epsilon_bits),
                   [&](auto val) { return val == 0 ? 1 : 0; });

    std::cout << bits_to_int(gamma_bits) * bits_to_int(epsilon_bits) << '\n';
}

auto part_two(const std::vector<std::string_view>& binary_strs) -> void {
    if (binary_strs.empty()) {
        throw std::runtime_error {"Empty input"};
    }

    //TODO remove scuffed code duplication
    std::vector<std::string_view> filtered = binary_strs;
    for (size_t i = 0; i < binary_strs[0].length(); ++i) {
        const auto one_counts = get_bit_counts(filtered);

        char most_common = one_counts[i] < filtered.size() / 2.0 ? '0' : '1'; 
        std::erase_if(filtered, [&](auto str){  return str[i] != most_common; });

        if (filtered.size() == 1) break;
    } 
    const auto oxygen_str = filtered[0];

    filtered = binary_strs;
    for (size_t i = 0; i < binary_strs[0].length(); ++i) {
        const auto one_counts = get_bit_counts(filtered);

        auto least_common = one_counts[i] < filtered.size() / 2.0 ? '1' : '0'; 
        std::erase_if(filtered, [&](auto str){  return str[i] != least_common; });

        if (filtered.size() == 1) break;
    } 
    const auto c02_str = filtered[0];

    const auto ox_bits = str_to_num_bits(oxygen_str);
    const auto c02_bits = str_to_num_bits(c02_str);

    std::cout << bits_to_int(ox_bits) * bits_to_int(c02_bits) << '\n';
}

auto solve() -> void {
    const auto str = read_file_to_string("../src/day3/input/input.txt");
    const auto binary_strs = tokenize(str);

    part_one(binary_strs);
    part_two(binary_strs);
}
}
