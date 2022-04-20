#pragma once

#include <vector>
#include <string_view>
#include <string>

auto read_file_to_string(const std::string_view file_path) -> std::string; 
auto tokenize(const std::string_view string) -> std::vector<std::string_view>;
