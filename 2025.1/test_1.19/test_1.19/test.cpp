#include <iostream>

// ����ڵ�Ķ���
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }

        // 1. ʹ�ÿ���ָ�����Ƿ���ڻ�
        ListNode* slow = head;
        ListNode* fast = head;
        bool hasCycle = false;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                hasCycle = true;
                break;
            }
        }

        // ���û�л�������nullptr
        if (!hasCycle) {
            return nullptr;
        }

        // 2. �ҵ��������
        // ��һ��ָ������ָ��ͷ�ڵ㣬��һ��ָ�뱣����������
        // ����ָ������ͬ�ٶ��ƶ��������㼴Ϊ�������
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

// ���Դ���
int main() {
    // ����һ������������: 1->2->3->4->5->3(��)
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;  // ������

    Solution solution;
    ListNode* cycleNode = solution.detectCycle(head);

    if (cycleNode != nullptr) {
        std::cout << "Found cycle at node with value: " << cycleNode->val << std::endl;
    }
    else {
        std::cout << "No cycle found in the linked list." << std::endl;
    }

    // ע�⣺ʵ��ʹ��ʱ��Ҫ��ȷ�ͷ��ڴ�
    // ���ڴ��ڻ�������ʡ��ɾ���ڵ�Ĵ���
    return 0;
}