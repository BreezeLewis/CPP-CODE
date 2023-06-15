#include <iostream>

struct listNode {
    listNode* prev, * next;
    int val;

    listNode() : val(0), prev(nullptr), next(nullptr) {}
    listNode(int v, listNode* p, listNode* n) : val(v), prev(p), next(n) {
        if (prev != nullptr)
            prev->next = this;
        if (next != nullptr)
            next->prev = this;
    }
};