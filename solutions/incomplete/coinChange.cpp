#include <algorithm>
#include <string>
#include <vector>
#include <string_view>
#include <memory>
#include <fmt/core.h>

auto solution(int amount, std::vector<int>& coins) -> int {
    std::vector<int> terms(amount + 1, 0);
    terms[0] = 1;

    for (auto c : coins) {
        for (int j = c; j <= amount; ++j) {
            terms[j] += terms[j - c];
        }
    }

    return terms[amount];
}

auto main() -> int {
    int amount = 5;
    std::vector<int> coins = { 1, 2, 5 };
    auto result = solution(amount, coins);
    fmt::print("{}\n", result);
    return 0;
}
