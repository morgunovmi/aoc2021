#pragma once

#include <cstdint>
#include <string_view>
#include <array>
#include <vector>

namespace daytwo {
struct position {
    uint32_t depth{};
    uint32_t horizontal{};
};

const std::array<std::string_view, 3> COMMANDS{"forward", "down", "up"};
enum COMMAND_OPTION {
    FORWARD = 0,
    DOWN = 1,
    UP = 2,
};

using cmd_pair = std::pair<COMMAND_OPTION, uint32_t>;

auto parse_commands(const std::vector<std::string_view>& commands) -> std::vector<cmd_pair>;
auto update_position(const std::vector<cmd_pair>& commands, position& pos) -> void;
auto solve() -> void;
}
