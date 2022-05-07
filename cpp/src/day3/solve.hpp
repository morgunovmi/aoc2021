#pragma once

#include <vector>
#include <string_view>

namespace daythree {

auto bits_to_int(const std::vector<uint8_t>& bits) -> int;

auto part_one(const std::vector<std::string_view>& binary_strs) -> void;
auto solve() -> void;

}
