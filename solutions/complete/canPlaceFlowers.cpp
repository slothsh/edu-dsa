#include <vector>
#include <fmt/core.h>

auto solution(std::vector<int>& flower_bed, int n) -> bool {
    int total_valid = 0;
    int size = flower_bed.size();

    for (int i = 0; i < static_cast<int>(flower_bed.size()); ++i) {
        bool current_empty = flower_bed[i] == 0;
        bool previous_empty = flower_bed[(i - 1 > 0) ? i - 1 : 0] == 0;
        bool next_empty = flower_bed[(i + 1 < size) ? i + 1 : size - 1] == 0;

        if (current_empty && previous_empty && next_empty) {
            ++total_valid;
            flower_bed[i] = 1;
        }
    }

    fmt::print("{}\n", total_valid);

    if (static_cast<int>(total_valid) >= n)
        return true;

    return false;
}

auto main() -> int {
    int n = 2;
    std::vector<int> flower_bed = { 1, 0, 0 };
    auto result = solution(flower_bed, n);
    fmt::print("{}\n", result);
    return 0;
}
