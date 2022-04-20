#include <iostream>
#include <cstring>

#include "solve.hpp"
#include "util/util.hpp"

auto daytwo::parse_commands(const std::vector<std::string_view>& command_strs) -> std::vector<cmd_pair> {
    std::vector<cmd_pair> commands{};
    for (const auto & cmd_str : command_strs) {
        cmd_pair cmd{};
        const auto parts = split_once(cmd_str, " ");
        for (uint8_t i = 0; i < COMMANDS.size(); ++i) {
            if (parts[0] == COMMANDS[i]) {
                cmd.first = static_cast<COMMAND_OPTION>(i);
                break;
            }
        }
        cmd.second = std::stoul(parts[1].data());
        commands.push_back(cmd);
    }
    return commands;
}

auto daytwo::update_position(const std::vector<cmd_pair>& commands, position& pos) -> void {
    for (const auto & cmd : commands) {
        switch (cmd.first) {
            case FORWARD:
                pos.horizontal += cmd.second;
                break;
            case DOWN:
                pos.depth += cmd.second;
                break;
            case UP:
                pos.depth -= cmd.second;
                break;
            default:
                throw std::runtime_error{"Undefined command type"};
        }
    }
}

auto daytwo::solve() -> void {
    const auto commands = tokenize(read_file_to_string("../src/day2/input/input.txt"));
    position pos{};

    update_position(parse_commands(commands), pos);

    std::cout << pos.depth * pos.horizontal << '\n';
}
