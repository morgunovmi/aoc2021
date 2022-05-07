#include <iostream>

#include "day1/solve.hpp"
#include "day2/solve.hpp"
#include "day3/solve.hpp"
#include "util/util.hpp"

#include <vector>
#include <string_view>
#include <algorithm>

auto main() -> int {
    dayone::solve();
    daytwo::solve();
    daythree::solve();

    return 0;
}
