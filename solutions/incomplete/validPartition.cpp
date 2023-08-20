#include <algorithm>
#include <string>
#include <vector>
#include <string_view>
#include <cmath>
#include <fmt/core.h>

// 1 1 1  1 1 2  3
// 1 1  1 1  1 2 3
//
// 1 1 1
//
// Stride 2:
// i = 0 => 1 1 => true
// i = 2 => 1   => false
//
// Strides by 2 until first false predicate is found,
// then stride once by three at occurence of false.
// Continue strides of 2 if true for stride of 3.
//
// Solution:
// 1 1
// 1 1
// 1 2 3 
//
// Stride 2:
// i = 0 => 1 1 => true
// i = 2 => 1 1 => true
// i = 4 => 1 2 => false
//
// Stride 3:
// i = 4 => 1 2 3 => true

auto solution(std::vector<int>& nums) -> bool {
    std::size_t n = nums.size();
    if (n == 1) return false;
    static bool valid[3] = {true, false, n > 1 && nums[0] == nums[1]};

    for (std::size_t i = 2; i < n; ++i) {
        bool current_valid = false;

        if (nums[i] == nums[i - 1] && valid[1])
            current_valid = true;
        else if (nums[i] == nums[i - 1] && nums[i] == nums[i - 2] && valid[0])
            current_valid = true;
        else if (nums[i] - nums[i - 1] == 1 && nums[i - 1] - nums[i - 2] == 1 && valid[0])
            current_valid = true;

        valid[0] = valid[1];
        valid[1] = valid[2];
        valid[2] = current_valid;
    }

    return valid[2];
}

auto main() -> int {
    std::vector<int> nums = { 473928, 473929, 473930 };
    fmt::print("nums: ");
    for (std::size_t i = 0; i < nums.size(); ++i) {
        fmt::print("{}{}", nums[i], ((i + 1 < nums.size()) ? ", " : ""));
    }
    fmt::print("\n");
    auto result = solution(nums);
    fmt::print("{}\n", result);
    return 0;
}
