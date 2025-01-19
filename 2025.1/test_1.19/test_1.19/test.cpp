#include <iostream>

// 链表节点的定义
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

        // 1. 使用快慢指针检测是否存在环
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

        // 如果没有环，返回nullptr
        if (!hasCycle) {
            return nullptr;
        }

        // 2. 找到环的入口
        // 将一个指针重新指向头节点，另一个指针保持在相遇点
        // 两个指针以相同速度移动，相遇点即为环的入口
        slow = head;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

// 测试代码
int main() {
    // 创建一个带环的链表: 1->2->3->4->5->3(环)
    ListNode* head = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    ListNode* node5 = new ListNode(5);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node3;  // 创建环

    Solution solution;
    ListNode* cycleNode = solution.detectCycle(head);

    if (cycleNode != nullptr) {
        std::cout << "Found cycle at node with value: " << cycleNode->val << std::endl;
    }
    else {
        std::cout << "No cycle found in the linked list." << std::endl;
    }

    // 注意：实际使用时需要正确释放内存
    // 由于存在环，这里省略删除节点的代码
    return 0;
}