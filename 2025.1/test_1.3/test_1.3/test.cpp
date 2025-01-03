// ���Դ�������߽���������ܡ��ڴ桢�쳣�������
#include <iostream>
#include <cassert>
#include <chrono>
#include <stdexcept>

class ListTest {
public:
    void testFunctionality() {
        // �������ܲ���
        assert(s.reverseList(nullptr) == nullptr);

        // ���ģ���� (100K�ڵ�)
        ListNode* large = createLargeList(100000);
        validateList(s.reverseList(large));

        // ѭ�����
        ListNode* cycle = createCycle();
        try {
            s.reverseList(cycle);
        }
        catch (...) {
            cycleDetected = true;
        }

        // �ڴ�й©����
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