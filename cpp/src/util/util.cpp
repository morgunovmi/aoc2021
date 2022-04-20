#include <fstream>
#include <iostream>

#include "util.hpp"

auto read_file_to_string(const std::string_view file_path) -> std::string {
    if (auto ifs = std::ifstream{ file_path.data() }) {
        return { std::istreambuf_iterator<char>{ifs}, {} };
    }
    throw std::runtime_error{"Failed to read file to string"};
}

auto tokenize(const std::string_view string) -> std::vector<std::string_view> {
    const std::string delims{"\r\n\t"};
    std::vector<std::string_view> parts{};
    for (auto beg = string.find_first_not_of(delims); beg != std::string::npos;) {
        auto end = string.find_first_of(delims, beg);
        parts.emplace_back(string.substr(beg, end - beg));
        beg = string.find_first_not_of(delims, end);
    }
    return parts;
}
