#include <algorithm>
#include <string>
#include <vector>
#include <string_view>
#include <cmath>
#include <fmt/core.h>

auto solution(std::vector<std::vector<int>>& grid) -> int {
    std::size_t total_paths = 0;
    std::size_t size_x = grid.size();
    std::size_t size_y = grid[0].size();

    std::size_t l = 1;
    std::size_t b = 1;

    while (l * b != size_x * size_y) {
        if (l == size_x) {
            ++b;
            l = 1;
        } else {
            ++l;
        }


        total_paths += ((size_x - l < 1) ? 0 : 1) + ((size_y - b < 1) ? 0 : 1);
    }

    return total_paths;
}

auto main() -> int {
    std::vector<std::vector<int>> grid = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0},
    };
    auto result = solution(grid);
    fmt::print("{}\n", result);
    return 0;
}
