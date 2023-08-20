#include <algorithm>
#include <string>
#include <vector>
#include <string_view>
#include <cmath>
#include <fmt/core.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ~ListNode() {
        fmt::print("deleting: {}\n", this->val);
        delete this->next;
    }
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    auto print(std::size_t depth = 0) -> void {
        for (std::size_t i = 0; i < depth; ++i) {
            fmt::print(" ");
        }
        fmt::print("{}\n", this->val);

        if (this->next != nullptr) {
            this->next->print(depth + 1);
        }
    }
};

auto solution(ListNode* head, int x) -> ListNode* {
    // TODO!
}

auto main() -> int {
    ListNode* head = new ListNode(
        1, new ListNode(
            4, new ListNode(
                3, new ListNode(
                    2, new ListNode(
                        5, new ListNode(2)
                    )
                )
            )
        )
    );

    auto result = solution(head, 3);
    fmt::print("ListNode:\n");
    result->print();
    delete head;
    return 0;
}
