#pragma once

#include <string_view>
#include <vector>

namespace dayone {
auto get_depths_from_str(const std::string_view str) -> std::vector<std::uint32_t>;
auto count_increasing(const std::vector<uint32_t>& depths, uint16_t window_size) -> uint32_t;
auto part_one(const std::vector<uint32_t>& depths) -> void;
auto part_two(const std::vector<uint32_t>& depths) -> void;
auto solve() -> void; 
}
