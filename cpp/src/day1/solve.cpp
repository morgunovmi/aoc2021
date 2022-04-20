#include <iostream>
#include <algorithm>
#include <numeric>

#include "solve.hpp"
#include "util/util.hpp"

auto dayone::get_depths_from_str(const std::string_view str) -> std::vector<std::uint32_t> {
    std::vector<std::uint32_t> depths{};
    auto strs = tokenize(str);
    std::transform(strs.begin(), strs.end(),
                   std::back_inserter(depths),
                   [](auto val){ return std::stoul(val.data()); });
    return depths;
}

auto dayone::count_increasing(const std::vector<uint32_t>& depths, uint16_t window_size) -> uint32_t {
    uint32_t count = 0;
    for (auto it = std::next(depths.begin(), window_size); it != depths.end(); ++it) {
        if (std::accumulate(std::prev(it, window_size + 1), it - 1, 0) <
            std::accumulate(std::prev(it, window_size), it, 0)) {
            ++count;
        } 
    }
    return count;
}

auto dayone::part_one(const std::vector<uint32_t>& depths) -> void {
    std::cout << 
        count_increasing(depths, 1) << '\n';
}

auto dayone::part_two(const std::vector<uint32_t>& depths) -> void {
    std::cout << 
        count_increasing(depths, 3) << '\n';
}

auto dayone::solve() -> void {
    const auto depths = get_depths_from_str(read_file_to_string("../src/day1/input/input.txt"));
    part_one(depths);
    part_two(depths);
}
