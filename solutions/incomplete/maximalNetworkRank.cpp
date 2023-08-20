#include <algorithm>
#include <vector>
#include <cstdint>
#include <cmath>
#include <fmt/core.h>
#include <limits>
#include <utility>
#include <tuple>
#include <map>

// auto solution(int n, std::vector<std::vector<int>>& roads) -> int {
//     if (roads.size() == 0) return 0;
//
//     std::map<int, std::pair<int, std::vector<int>>> total_edges{};
//     for (int i = 0; i < n; ++i) {
//         total_edges[i] = std::make_pair<int, std::vector<int>>(0, {});
//     }
//
//     for (auto const& edge : roads) {
//         ++total_edges[edge[0]].first;
//         total_edges[edge[0]].second.push_back(edge[1]);
//         ++total_edges[edge[1]].first;
//         total_edges[edge[1]].second.push_back(edge[0]);
//     }
//
//     int key_a = 0;
//     int key_b = 0;
//     int max_one = 0;
//     int max_two = 0;
//     for (auto const& total : total_edges) {
//         if (total.second.first > max_one) {
//             max_one = total.second.first;
//             key_a = total.first;
//         }
//
//         else if (total.second.first > max_two) {
//             max_two = total.second.first;
//             key_b = total.first;
//         }
//
//         fmt::print("{}: {}\n", total.first, total.second.first);
//     }
//
//     fmt::print("\nkeys: {} {}\n", key_a, key_b);
//     int overlap = 0;
//     for (auto a : total_edges[key_a].second) {
//         fmt::print("{}: {}\n", a, key_b);
//         if (a == key_b) ++overlap;
//     }
//
//     return max_one + max_two - overlap;
// }

auto solution(int n, std::vector<std::vector<int>>& roads) -> int {
    if (roads.size() == 0) return 0;

    std::vector<std::tuple<int, int, std::vector<int>>> total_edges(n);
    for (int i = 0; i < n; ++i) {
        total_edges[i] = std::tuple<int, int, std::vector<int>>{i, 0, {}};
    }

    for (auto const& edge : roads) {
        ++std::get<1>(total_edges[edge[0]]);
        std::get<2>(total_edges[edge[0]]).push_back(edge[1]);
        ++std::get<1>(total_edges[edge[1]]);
        std::get<2>(total_edges[edge[1]]).push_back(edge[0]);
    }

    std::sort(total_edges.begin(), total_edges.end(),
              [](auto const& a, auto const& b) {
                  int city_a = std::get<0>(a);
                  int city_b = std::get<0>(b);

                  for (auto a : std::get<2>(a)) {
                      for (auto b : std::get<2>(b)) {
                          if (city_a == b || city_b == a) return false;
                      }
                  }

                  return true;
              });

    std::stable_sort(total_edges.begin(), total_edges.end(),
              [](auto const& a, auto const& b) {
                  return std::get<1>(a) > std::get<1>(b);
              });

    int overlap = 0;
    int city_a = std::get<0>(total_edges[0]);
    int city_b = std::get<0>(total_edges[1]);
    fmt::print("cities: {} {}\n", std::get<0>(total_edges[0]), city_b);
    for (auto city_a_dest : std::get<2>(total_edges[0])) {
        fmt::print("{}: {}\n", city_a_dest, city_b);
        if (city_a_dest == city_b) ++overlap;
    }

    return std::get<1>(total_edges[0]) + std::get<1>(total_edges[1]) - overlap;
}

auto main() -> int {
    // int n = 4;
    // std::vector<std::vector<int>> roads = { {0, 1}, {0, 3}, {1, 2}, {1, 3} };
    // int n = 5;
    // std::vector<std::vector<int>> roads = { {0, 1}, {0, 3}, {1, 2}, {1, 3}, {2, 3}, {2, 4} };
    int n = 8;
    std::vector<std::vector<int>> roads = { {0, 1}, {1, 2}, {2, 3}, {2, 4}, {5, 6}, {5, 7} };
    // int n = 2;
    // std::vector<std::vector<int>> roads = { {0, 1} };
    // int n = 5;
    // std::vector<std::vector<int>> roads = { {2, 3}, {0, 3}, {0, 4}, {4, 1} };
    // int n = 8;
    // std::vector<std::vector<int>> roads = { {4, 6}, {5, 2}, {3, 5}, {7, 5}, {7, 6} };

    fmt::print("roads: [ ");
    for (std::size_t i = 0; i < roads.size(); ++i) {
        fmt::print("[");
        for (std::size_t j = 0; j < roads[i].size(); ++j) {
            fmt::print("{}{}", roads[i][j], ((j + 1 < roads[i].size()) ? ", " : ""));
        }
        fmt::print("]{}", ((i + 1 < roads.size()) ? ", " : ""));
    }
    fmt::print(" ]\n");
    auto result = solution(n, roads);
    fmt::print("{}\n", result);
    return 0;
}
