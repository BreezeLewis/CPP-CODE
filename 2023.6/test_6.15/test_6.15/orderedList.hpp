#pragma once

#include "listnode.h"

class OrderedList {
public:
    OrderedList() : root(nullptr) {}

    virtual ~OrderedList() {
        while (root != nullptr) {
            auto temp = root;
            root = root->next;
            delete temp;
        }
    }

    virtual void insert(int val) = 0;

    virtual void printList() const {
        for (auto cur = root; cur != nullptr; cur = cur->next) {
            std::cout << cur->val;
            if (cur->next != nullptr) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

protected:
    listNode* root;
};

class AscendOrderedList : public OrderedList {
public:
    void insert(int val) override
    {
        if (root == nullptr)
        {
            root = new listNode(val, nullptr, nullptr);
            return;
        }

        auto cur = root;
        if (val < cur->val)
        {
            root = new listNode(val, nullptr, cur);
            cur->prev = root;
            return;
        }
        while (cur)
        {
            if (cur->val <= val)
            {
                auto pre = cur;
                cur = cur->next;
                if (cur == nullptr)
                {
                    pre->next = new listNode(val, pre, nullptr);
                }
            }
            else if (cur->val > val)
            {
                auto newNode = new listNode(val, cur->prev, cur);
                return;
            }
        }

        return;
    }
};

class DescendOrderedList : public OrderedList {
public:
    void insert(int val) override
    {
        if (root == nullptr)
        {
            root = new listNode(val, nullptr, nullptr);
            return;
        }

        auto cur = root;
        if (val > cur->val)
        {
            root = new listNode(val, nullptr, cur);
            cur->prev = root;
            return;
        }
        while (cur)
        {
            if (cur->val >= val)
            {
                auto pre = cur;
                cur = cur->next;
                if (cur == nullptr)
                {
                    pre->next = new listNode(val, pre, nullptr);
                }
            }
            else if (cur->val < val)
            {
                auto newNode = new listNode(val, cur->prev, cur);
                return;
            }
        }

        return;
    }
};
