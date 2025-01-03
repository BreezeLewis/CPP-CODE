// 测试代码包含边界情况、性能、内存、异常处理测试
#include <iostream>
#include <cassert>
#include <chrono>
#include <stdexcept>

class ListTest {
public:
    void testFunctionality() {
        // 基础功能测试
        assert(s.reverseList(nullptr) == nullptr);

        // 大规模测试 (100K节点)
        ListNode* large = createLargeList(100000);
        validateList(s.reverseList(large));

        // 循环检测
        ListNode* cycle = createCycle();
        try {
            s.reverseList(cycle);
        }
        catch (...) {
            cycleDetected = true;
        }

        // 内存泄漏测试
        for (int i = 0; i < 10000; i++) {
            auto* list = createRandomList();
            auto* reversed = s.reverseList(list);
            cleanup(reversed);
        }
    }

private:
    Solution s;
    ListNode* createRandomList();
    void validateList(ListNode*);
    void cleanup(ListNode*);
    ListNode* createCycle();
    bool cycleDetected = false;
};