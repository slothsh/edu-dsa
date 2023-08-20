#include <algorithm>
#include <string>
#include <string_view>
#include <fmt/core.h>
#include <vector>

struct MinMaxString {
    std::string_view const& max;
    std::string_view const& min;
    MinMaxString(std::string_view const& left, std::string_view const& right)
        : max((left.length() >= right.length()) ? left : right)
        , min((left.length() < right.length()) ? left : right)
    {}
};

auto get_chunk(std::string_view const& source, std::size_t const begin, std::size_t const end) -> std::string {
    std::string destination("", end - begin);
    std::copy(source.begin() + begin, source.begin() + end, destination.begin());
    return destination;
}

auto solution(std::string_view word1, std::string_view word2) -> std::string {
    auto const& max = MinMaxString(word1, word2).max;
    auto const& min = MinMaxString(word1, word2).min;
    std::size_t length_min = min.length();

    while (length_min != 0) {
        bool all_match = false;
        auto head_min = min.substr(0, length_min);
        auto tail_min = min.substr(length_min, min.length() - length_min);
        std::string chunks("", length_min);

        for (std::size_t i = 0; i < max.length(); i += length_min) {
            std::copy(max.begin() + i, max.begin() + i + length_min, chunks.begin());

            if (chunks == head_min)
                all_match = true;
            else
                all_match = false;
            fmt::print("{} == {} = {}\n", chunks, head_min, all_match);
        }

        for (std::size_t i = 0; i < tail_min.length(); i += length_min) {
            std::copy(tail_min.begin() + i, tail_min.begin() + i + length_min, chunks.begin());
            if (chunks == head_min)
                all_match = true;
            else
                all_match = false;
            fmt::print("{} == {} = {}\n", chunks, head_min, all_match);
        }

        if (all_match)
            return head_min.data();

        length_min /= 2;
    }

    return "";
}

auto main() -> int {
    auto result = solution("1212", "121212");
    fmt::print("{}\n", result);
    return 0;
}
