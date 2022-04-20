#pragma once

#include <vector>
#include <string_view>
#include <string>
#include <array>

auto read_file_to_string(const std::string_view file_path) -> std::string; 
auto split_once(const std::string_view string, const std::string_view delim) -> std::array<std::string_view, 2>;
auto tokenize(const std::string_view string) -> std::vector<std::string_view>;
