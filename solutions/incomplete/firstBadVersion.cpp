// Copyright (C) Stefan Olivier
// <https://stefanolivier.com>
// ----------------------------
// LeetCode : First Bad Version
// https://leetcode.com/problems/binary-search/?envType=study-plan&id=algorithm-ihttps://leetcode.com/problems/first-bad-version/?envType=study-plan&id=algorithm-i
/*
    You are a product manager and currently leading a team to develop a new product.
    Unfortunately, the latest version of your product fails the quality check.
    Since each version is developed based on the previous version,
    all the versions after a bad version are also bad.

    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one,
    which causes all the following ones to be bad.

    You are given an API bool isBadVersion(version) which returns whether version is bad.
    Implement a function to find the first bad version.
    You should minimize the number of calls to the API.
*/

#include <fmt/core.h>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>

bool isBadVersion([[maybe_unused]] int version)
{
    // TODO: implement
    return true;
}
 
int firstBadVersion(int n) {
    std::vector<int> versions(n);
    std::iota(versions.begin(), versions.end(), 1);

    std::size_t left = 0;
    std::size_t right = versions.size() - 2;
    int middle = std::ceil(static_cast<float>(left + right) / 2.0f);
    int previous_bad_version = middle;

    while (left != right) {

        if (isBadVersion(versions.at(middle))) {
            right = middle - 1;
            if (previous_bad_version < middle)
                return versions.at(middle);
        }

        else {
            left = middle;
        }

        middle = std::ceil(static_cast<float>(left + right) / 2.0f);
    }

    if (isBadVersion(versions.at(left))) return versions.at(left);

    return versions.at(middle);
}

auto main() -> int {
    // TODO
    return 0;
}
