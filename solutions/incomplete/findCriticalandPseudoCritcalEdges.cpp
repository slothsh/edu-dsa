#include <algorithm>
#include <vector>
#include <cstdint>
#include <cmath>
#include <fmt/core.h>
#include <limits>
#include <utility>
#include <tuple>
#include <map>

auto solution(int n, std::vector<std::vector<int>>& edges) -> std::vector<std::vector<int>> {
    std::vector<std::tuple<int, std::vector<int>>> graph(n, std::tuple{0, std::vector<int>{}});
    for (auto const& edge : edges) {
        std::get<0>(graph[edge[0]]) = edge[0];
        std::get<1>(graph[edge[0]]).push_back(edge[1]);
        std::get<0>(graph[edge[1]]) = edge[1];
        std::get<1>(graph[edge[1]]).push_back(edge[0]);
    }

    for (auto const& [i, edges] : graph) {
        fmt::print("vertex: {}\n", i);
        for (auto e : edges) {
            fmt::print("    {}\n", e);
        }
    }
    fmt::print("\n");

    std::vector<std::tuple<int, std::vector<int>>> forest(graph.begin(), graph.end());
    for (auto& f : forest) {
        std::get<1>(f).clear();
    }

    bool completed = false;
    while (!completed) {
        std::vector<int> components{};
        for (auto const& [v, edges] : graph) {
            for (auto e : edges) {

            }
        }
    }

    return {};
}

auto main() -> int {
    int n = 5;
    std::vector<std::vector<int>> edges = {
        {0, 1, 1},
        {1, 2, 1},
        {2, 3, 2},
        {0, 3, 2},
        {0, 4, 3},
        {3, 4, 3},
        {1, 4, 6}
    };

    fmt::print("edges: [ ");
    for (std::size_t i = 0; i < edges.size(); ++i) {
        fmt::print("[");
        for (std::size_t j = 0; j < edges[i].size(); ++j) {
            fmt::print("{}{}", edges[i][j], ((j + 1 < edges[i].size()) ? ", " : ""));
        }
        fmt::print("]{}", ((i + 1 < edges.size()) ? ", " : ""));
    }

    fmt::print(" ]\n");
    auto result = solution(n, edges);
    for (std::size_t i = 0; i < result.size(); ++i) {
        fmt::print("[");
        for (std::size_t j = 0; j < result[i].size(); ++j) {
            fmt::print("{}{}", result[i][j], ((j + 1 < result[i].size()) ? ", " : ""));
        }
        fmt::print("]{}", ((i + 1 < result.size()) ? "\n" : ""));
    }
    return 0;
}
