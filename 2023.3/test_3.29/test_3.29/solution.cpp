#define _CRT_SECURE_NO_WARNINGS
#include"ListNode.h"
ListNode* reverseList(ListNode* head)
{

    ListNode* newhead = new ListNode(head->val);
    ListNode* tail = nullptr;
    while (head)
    {
        ListNode* newnode = new ListNode(head->val);
        newnode->next = tail;
        tail = newnode;
        head = head->next;
    }
    newhead->next = tail;
    return newhead->next;
}