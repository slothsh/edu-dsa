#include <algorithm>
#include <queue>
#include <string>
#include <vector>
#include <string_view>
#include <cmath>
#include <fmt/core.h>

auto solution(std::vector<int>& nums, int k) -> int {
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap(
        nums.begin(), nums.begin() + k
    );

    for (int i = k; i < static_cast<int>(nums.size()); ++i) {
        if (nums[i] > min_heap.top()) {
            min_heap.pop();
            min_heap.push(nums[i]);
        }
    }

    return min_heap.top();
}

auto main() -> int {
    int k = 3;
    std::vector<int> nums = { 3, 2, 1, 5, 6, 4 };

    fmt::print("k = {}\nnums: ", k);
    for (std::size_t i = 0; i < nums.size(); ++i) {
        fmt::print("{}{}", nums[i], ((i + 1 < nums.size()) ? ", " : ""));
    }
    fmt::print("\n");
    auto result = solution(nums, k);
    fmt::print("{}\n", result);
    return 0;
}
