#include <algorithm>
#include <string>
#include <vector>
#include <string_view>
#include <memory>
#include <fmt/core.h>

auto solution(std::vector<std::vector<int>>& grid) -> int {
    int total_paths = 0;

    std::size_t rows = grid.size();
    std::size_t cols = grid[0].size();
    std::size_t total_moves = rows + cols - 2;
}

auto main() -> int {
    std::vector<std::vector<int>> grid = { {0, 0, 0}, {0, 0, 0} };
    auto result = solution(grid);
    fmt::print("{}\n", result);
    return 0;
}
