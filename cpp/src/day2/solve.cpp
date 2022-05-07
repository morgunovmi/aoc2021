#include <iostream>

#include "solve.hpp"

#include "util/util.hpp"

auto daytwo::parse_commands(const std::vector<std::string_view>& command_strs)
-> std::vector<cmd_pair> {
    std::vector<cmd_pair> commands{};
    for (const auto& cmd_str : command_strs) {
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

auto daytwo::update_position(const std::vector<cmd_pair>& commands,
                                 position& pos, uint8_t part) -> void {
    for (const auto& cmd : commands) {
        switch (cmd.first) {
            case FORWARD:
                if (part == 1) {
                    pos.horizontal += cmd.second;
                } else {
                    pos.horizontal += cmd.second;
                    pos.depth += cmd.second * pos.aim;
                }
                break;
            case DOWN:
                if (part == 1) {
                    pos.depth += cmd.second;
                } else {
                    pos.aim += cmd.second;
                }
                break;
            case UP:
                if (part == 1) {
                    pos.depth -= cmd.second;
                } else {
                    pos.aim -= cmd.second;
                }
                break;
            default:
                throw std::runtime_error{"Undefined command type"};
        }
    }
}

auto daytwo::part_one(const std::vector<std::string_view>& command_strs) -> void {
    position pos{};
    update_position(parse_commands(command_strs), pos, 1);
    std::cout << pos.depth * pos.horizontal << '\n';
}

auto daytwo::part_two(const std::vector<std::string_view>& command_strs) -> void {
    position pos{};
    update_position(parse_commands(command_strs), pos, 2);
    std::cout << pos.depth * pos.horizontal << '\n';
}

auto daytwo::solve() -> void {
    const auto str = read_file_to_string("../src/day2/input/input.txt");
    const auto commands_strs = tokenize(str);

    part_one(commands_strs);
    part_two(commands_strs);
}
