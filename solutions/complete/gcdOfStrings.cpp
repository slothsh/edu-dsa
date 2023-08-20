#include <algorithm>
#include <string>
#include <string_view>
#include <ranges>
#include <fmt/core.h>
#include <iostream>
#include <vector>
#include <cstdint>
#include <limits>

struct MinMaxString {
    std::string_view const& max;
    std::string_view const& min;
    MinMaxString(std::string_view const& left, std::string_view const& right)
        : max((left.length() >= right.length()) ? left : right)
        , min((left.length() < right.length()) ? left : right)
    {}
};

auto solution(std::string_view word1, std::string_view word2) -> std::string {
    auto const& max = MinMaxString(word1, word2).max;
    auto const& min = MinMaxString(word1, word2).min;
    std::size_t length_min = min.length();
    auto const min_start = min.begin();
    auto const min_end = min.end();

    while (length_min != 0) {

        auto const min_head = std::ranges::subrange(min_start, min_start + length_min);
        auto const min_tail = std::ranges::subrange(min_start + length_min, min_end);
        auto const max_chunks = max | std::views::chunk(length_min);
        auto const min_chunks = min_tail | std::views::chunk(length_min);

        std::uint64_t all_match = std::numeric_limits<std::uint64_t>::max() << (max_chunks.size() + min_chunks.size());
        std::uint64_t i = 1;
        fmt::print("{:064b}\n", all_match);

        for (auto const c : max_chunks) {
            if (std::string_view(c) == std::string_view(min_head))
                all_match |= i;

            i <<= 1;
            fmt::print("{} == {} = {:064b}\n", std::string_view(c), std::string_view(min_head), all_match);
        }

        for (auto const c : min_chunks) {
            if (std::string_view(c) == std::string_view(min_head))
                all_match |= i;

            i <<= 1;
            fmt::print("{} == {} = {:064b}\n", std::string_view(c), std::string_view(min_head), all_match);
        }

        fmt::print("{:064b}\n", all_match);
        if (all_match == std::numeric_limits<std::uint64_t>::max()) {
            return min_head.data();
        }

        length_min /= 2;
    }

    return "";
}

auto main() -> int {
    auto result = solution("1212", "121212");
    fmt::print("{}\n", result);
    return 0;
}
