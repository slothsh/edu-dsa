// Copyright (C) Stefan Olivier
// <https://stefanolivier.com>
// ----------------------------
// LeetCode : Binary Search
// https://leetcode.com/problems/binary-search/?envType=study-plan&id=algorithm-i
/*
    Given an array of integers nums which is sorted in ascending order, and an
    integer target, write a function to search target in nums. If target exists,
    then return its index. Otherwise, return -1.

    You must write an algorithm with O(log n) runtime complexity.
*/

#include <algorithm>
#include <cmath>
#include <cctype>
#include <fmt/core.h>
#include <string>
#include <string_view>
#include <vector>

bool is_number(const std::string_view number_string)
{
    for (auto c : number_string) {
        if (!std::isdigit(c)) return false;
    }

    return true;
}

int binary_search(const std::vector<int> &nums, int target)
{
    std::size_t left = 0;
    std::size_t right = nums.size() - 1;

    while (left != right) {
        std::size_t middle = std::ceil(static_cast<float>(left + right) / 2.0f);
        if (nums.at(middle) > target) right = middle - 1;
        else left = middle;
    }

    if (nums.at(left) == target) return left;

    return -1;
}

int main(int argc, char** argv)
{
    if (argc < 2) {
        fmt::print("error: not enough arguments, please provide a single number as input\n");
        std::exit(EXIT_FAILURE);
    }

    int target = 0;
    if (is_number(argv[1])) 
        target = std::stoi(argv[1]);
    else {
        fmt::print("error: please provide a valid number as an argument to compare");
        std::exit(EXIT_FAILURE);
    }

    const std::vector list{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    const auto result = binary_search(list, target);
    fmt::print("result: {}\n", result);
}
