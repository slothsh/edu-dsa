#include <algorithm>
#include <vector>
#include <cstdint>
#include <utility>
#include <cmath>
#include <deque>
#include <fmt/core.h>

auto solution(std::vector<int>& nums, int k) -> std::vector<int> {
    int size = nums.size();
    std::deque<int> max_index;
    std::vector<int> result(size - k + 1);

    for (int i = 0; i < size; ++i) {
        while(!max_index.empty() && nums[i] >= nums[max_index.back()]) {
            max_index.pop_back();
        }

        max_index.push_back(i);

        fmt::print("max index:\n    ");
        for (std::size_t j = 0; j < max_index.size(); ++j) {
            fmt::print("{}{}", max_index[j], ((j + 1 < max_index.size()) ? ", " : ""));
        }
        fmt::print("\n");

        if (max_index.front() == i - k) {
            max_index.pop_front(); 
            fmt::print("popping\n");
        }

        if (i >= k - 1) {
            result[i - k + 1] = nums[max_index.front()];
            fmt::print("pushing\n");
        }
    }

    return result;
}

auto main() -> int {
    int k = 3;
    std::vector<int> nums = { 1, 3, -1, -3, 5, 3, 6, 7 };
    fmt::print("nums: ");
    for (std::size_t i = 0; i < nums.size(); ++i) {
        fmt::print("{}{}", nums[i], ((i + 1 < nums.size()) ? ", " : ""));
    }
    fmt::print("\n");
    auto result = solution(nums, k);
    for (auto r : result) {
        fmt::print("{}\n", r);
    }
    return 0;
}
