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

auto part_one(const std::vector<std::string_view>& binary_strs) -> void {
    if (binary_strs.empty()) {
        throw std::runtime_error {"Empty input"};
    }

    const auto len = binary_strs[0].length();
    std::vector<uint32_t> gamma_counts(len);
    for (const auto & str : binary_strs) {
        for (size_t i = 0; i < len; ++i) {
            gamma_counts[i] += str[i] - '0';
        }
    }

    std::vector<uint8_t> gamma_bits{}; 
    std::transform(gamma_counts.begin(), gamma_counts.end(), std::back_inserter(gamma_bits),
                   [&](auto val) { return val > binary_strs.size() / 2 ? 1 : 0; });

    std::vector<uint8_t> epsilon_bits{}; 
    std::transform(gamma_bits.begin(), gamma_bits.end(), std::back_inserter(epsilon_bits),
                   [&](auto val) { return val == 0 ? 1 : 0; });

    std::cout << bits_to_int(gamma_bits) * bits_to_int(epsilon_bits) << '\n';
}

auto solve() -> void {
    const auto str = read_file_to_string("../src/day3/input/input.txt");
    const auto binary_strs = tokenize(str);

    part_one(binary_strs);
}
}
