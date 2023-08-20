#include <algorithm>
#include <string>
#include <string_view>
#include <vector>
#include <fmt/core.h>

auto solution(std::vector<int>& candies, int extra_candy) -> std::vector<bool> {
    int greatest = 0;

    for (auto c : candies) {
        if (greatest < c)
            greatest = c;
    }

    std::vector<bool> result(candies.size(), false);
    std::size_t i = 0;
    for (auto c : candies) {
        if (c + extra_candy >= greatest) {
            result[i] = true;
        }

        ++i;
    }

    return result;
}

auto main() -> int {
    std::vector<int> candies = { 1, 3, 5, 6, 0, 2, 9 };
    auto result = solution(candies, 3);

    for (auto v : result) {
        fmt::print("{}\n", bool(v));
    }

    return 0;
}
