#include <iostream>
#include <cassert>
#include <chrono>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 修改 Solution 类，添加循环检测
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;

        // 检测循环
        if (hasCycle(head)) {
            throw std::runtime_error("Cycle detected in linked list");
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

private:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};

class ListTest {
public:
    // 测试用例1：空链表测试
    void testEmptyList() {
        Solution s;
        assert(s.reverseList(nullptr) == nullptr);
        std::cout << "Empty list test passed\n";
    }

    // 测试用例2：单节点测试 
    void testSingleNode() {
        ListNode* head = new ListNode(1);
        Solution s;
        ListNode* result = s.reverseList(head);
        assert(result->val == 1);
        assert(result->next == nullptr);
        delete result;
        std::cout << "Single node test passed\n";
    }

    // 测试用例3：多节点测试
    void testMultipleNodes() {
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);

        Solution s;
        ListNode* result = s.reverseList(head);
        assert(result->val == 3);
        assert(result->next->val == 2);
        assert(result->next->next->val == 1);
        assert(result->next->next->next == nullptr);

        cleanup(result);
        std::cout << "Multiple nodes test passed\n";
    }

    // 测试用例4：性能测试
    void testPerformance() {
        const int NODE_COUNT = 10000;

        auto start_create = std::chrono::high_resolution_clock::now();
        ListNode* head = createLargeList(NODE_COUNT);
        auto end_create = std::chrono::high_resolution_clock::now();

        Solution s;
        auto start_reverse = std::chrono::high_resolution_clock::now();
        ListNode* result = s.reverseList(head);
        auto end_reverse = std::chrono::high_resolution_clock::now();

        validateReversed(result, NODE_COUNT - 1);

        auto create_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_create - start_create);
        auto reverse_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_reverse - start_reverse);

        std::cout << "Performance test:\n"
            << "Creation time: " << create_time.count() << "ms\n"
            << "Reverse time: " << reverse_time.count() << "ms\n";

        cleanup(result);
    }

    // 测试用例5：内存泄漏检测
    void testMemoryLeak() {
        const int ITERATIONS = 1000;
        Solution s;

        for (int i = 0; i < ITERATIONS; i++) {
            ListNode* head = createLargeList(100);
            ListNode* result = s.reverseList(head);
            cleanup(result);  // 确保每次都清理内存
        }
        std::cout << "Memory leak test passed\n";
    }

    // 测试用例6：异常情况测试
    void testEdgeCases() {
        Solution s;

        // 循环链表测试
        ListNode* cycle = new ListNode(1);
        cycle->next = new ListNode(2);
        cycle->next->next = new ListNode(3);
        cycle->next->next->next = cycle; // 创建循环

        try {
            s.reverseList(cycle);
            assert(false); // 应该抛出异常
        }
        catch (const std::runtime_error& ) {
            std::cout << "Cycle detection test passed\n";
        }

        // 清理内存
        cycle->next->next->next = nullptr;
        cleanup(cycle);
    }

private:
    ListNode* createLargeList(int size) {
        ListNode* head = nullptr;
        ListNode* curr = nullptr;
        for (int i = 0; i < size; i++) {
            if (!head) {
                head = new ListNode(i);
                curr = head;
            }
            else {
                curr->next = new ListNode(i);
                curr = curr->next;
            }
        }
        return head;
    }

    void validateReversed(ListNode* head, int expectedStart) {
        ListNode* curr = head;
        int expected = expectedStart;
        while (curr) {
            assert(curr->val == expected--);
            curr = curr->next;
        }
    }

    void cleanup(ListNode* head) {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ListTest test;
    test.testEmptyList();
    test.testSingleNode();
    test.testMultipleNodes();
    test.testPerformance();
    test.testMemoryLeak();
    test.testEdgeCases();
    std::cout << "All tests passed!\n";
    return 0;
}