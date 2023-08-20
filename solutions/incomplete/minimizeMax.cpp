#include <algorithm>
#include <string>
#include <string_view>
#include <vector>
#include <tuple>
#include <cmath>
#include <fmt/core.h>

bool solve(std::vector<int>& nums, int d, int p){
    std::size_t n = nums.size();
    int c = 0;

    for (std::size_t i = 0; i  < n - 1; ++i){
        if (nums[i + 1] - nums[i] <= d) {
            ++c;
            ++i;
        }

        if (c >= p)
            return true;
    }

    return false;
}

auto solution(std::vector<int>& nums, int p) -> int {
    std::sort(nums.begin(), nums.end());
    std::size_t n = nums.size();

    int lo = 0;
    int hi = nums[n-1] - nums[0];

    while (lo < hi) {
        int mid = (lo + hi) / 2;

        if (solve(nums, mid, p))
            hi = mid;
        else
            lo = mid + 1;
    }

    return lo;
}

auto main() -> int {
    int p = 2;
    std::vector<int> numbers = { 1, 1, 0, 3 };
    auto result = solution(numbers, p);
    fmt::print("{}\n", result);
    return 0;
}
