#include <algorithm>
#include <string>
#include <vector>
#include <string_view>
#include <fmt/core.h>

auto solution(std::vector<int>& nums, int target) -> bool {
    if (nums[0] - target <= nums[nums.size() - 1] - target) {
        for (int i = 0; i < nums.size(); ++i) {
            fmt::print("{}: {}: {}\n", nums[0] - target, nums[1] - target, i);
            if (nums[i] == target) {
                return true;
            }
        }
    }

    else {
        for (int i = nums.size() - 1; i >= 0; --i) {
            fmt::print("{}: {}: {}\n", nums[0] - target, nums[1] - target, i);
            if (nums[i] == target) {
                return true;
            }
        }
    }

    return false;
}

auto main() -> int {
    std::vector<int> rotated = { 4, 5, 6, 7, 0, 1, 2, 3 };
    int target = 4;

    auto result = solution(rotated, target);
    fmt::print("{}\n", result);
    return 0;
}
