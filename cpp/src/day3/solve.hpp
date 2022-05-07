#pragma once

#include <vector>
#include <string_view>

namespace daythree {

auto bits_to_int(const std::vector<uint8_t>& bits) -> int;
auto get_bit_counts(const std::vector<std::string_view>& binary_strs) -> std::vector<uint32_t>;
auto str_to_num_bits(const std::string_view str) -> std::vector<uint8_t>;

auto part_one(const std::vector<std::string_view>& binary_strs) -> void;
auto part_two(const std::vector<std::string_view>& binary_strs) -> void;
auto solve() -> void;

}
