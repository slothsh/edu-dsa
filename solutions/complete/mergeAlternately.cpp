#include <algorithm>
#include <string>
#include <string_view>
#include <fmt/core.h>

auto solution(std::string_view word1, std::string_view word2) -> std::string {
    std::size_t length1 = word1.length();
    std::size_t length2 = word2.length();
    std::string merged('\0', length1 + length2);
    std::size_t max_length = (length1 >= length2) ? length1 : length2;

    for (std::size_t i = 0; i < max_length; ++i) {
        if (i < length1)
            merged += word1[i];
        if (i < length2)
            merged += word2[i];
    }

    return merged;
}

auto main() -> int {
    auto result = solution("foo", "bar");
    fmt::print("{}\n", result);
    return 0;
}
