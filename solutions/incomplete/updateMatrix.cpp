#include <algorithm>
#include <vector>
#include <cstdint>
#include <utility>
#include <cmath>
#include <deque>
#include <fmt/core.h>

auto solution(std::vector<std::vector<int>>& mat) -> std::vector<std::vector<int>> {
    int size_y = mat.size();
    int size_x = mat[0].size();
    std::vector<std::vector<int>> result(size_y, std::vector<int>(size_x, 0));

    for (int i = 0; i < size_y; ++i) {
        for (int j = 0; j < size_x; ++j) {
            if (mat[i][j] == 0) {
                result[i][j] = 0;
            }

            else {
                int closest = 0;
                int distance = 1;

                int down = i + distance;
                int up = i - distance;
                int right = j + distance;
                int left = j - distance;

                bool row_down = down < size_y;
                bool row_up = up >= 0;
                bool col_right = right < size_x;
                bool col_left = left >= 0;

                while (closest == 0 && (row_down || row_up || col_right || col_left)) {
                    down = i + distance;
                    up = i - distance;
                    right = j + distance;
                    left = j - distance;
                    row_down = down < size_y;
                    row_up = up >= 0;
                    col_right = right < size_x;
                    col_left = left >= 0;

                    // down
                    if (row_down && mat[down][j] == 0) { closest = distance; }

                    // up
                    else if (row_up && mat[up][j] == 0) { closest = distance; }

                    // right
                    else if (col_right && mat[i][right] == 0) { closest = distance; }

                    // left
                    else if (col_left && mat[i][left] == 0) { closest = distance; }

                    // down + step right
                    else if (row_down && col_right && mat[down][right] == 0) { closest = distance + distance; }

                    // down + step left
                    else if (row_down && col_left && mat[down][left] == 0) { closest = distance + distance; }

                    // up + step 
                    else if (row_up && col_right && mat[up][right] == 0) { closest = distance + distance; }

                    // row up + col left
                    else if (row_up && col_left && mat[up][left] == 0) { closest = distance + distance; }

                    ++distance;
                }
                result[i][j] = closest;
            }
        }
    }

    return result;
}

auto main() -> int {
    // std::vector<std::vector<int>> matrix = { {0, 0, 0}, {0, 1, 0}, {0, 0, 0} };
    // std::vector<std::vector<int>> matrix = { {0, 0, 0}, {0, 1, 0}, {1, 1, 1} };
    // std::vector<std::vector<int>> matrix = { {0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0}, {0, 1, 0} };

    std::vector<std::vector<int>> matrix = {
        {1, 0, 1, 1, 0, 0, 1, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 0, 1, 1},
        {0, 0, 1, 0, 1, 0, 0, 1, 0, 0},
        {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        {0, 1, 0, 1, 0, 1, 0, 0, 1, 1},
        {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
        {1, 1, 1, 1, 1, 1, 1, 0, 1, 0},
        {1, 1, 1, 1, 0, 1, 0, 0, 1, 1}
    };

    fmt::print("matrix: [ ");
    for (std::size_t i = 0; i < matrix.size(); ++i) {
        fmt::print("[");
        for (std::size_t j = 0; j < matrix[i].size(); ++j) {
            fmt::print("{}{}", matrix[i][j], ((j + 1 < matrix[i].size()) ? ", " : ""));
        }
        fmt::print("]{}", ((i + 1 < matrix.size()) ? ", " : ""));
    }
    fmt::print(" ]\n");

    auto result = solution(matrix);
    for (auto r : result) {
        for (auto c : r) {
            fmt::print("{}\n", c);
        }
    }
    return 0;
}
