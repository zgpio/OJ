#include "lclib.h"
#include <iostream>
#include <vector>
ListNode *conv(std::vector<int> a)
{
    ListNode *head = new ListNode(-1);
    ListNode *tail = head;
    for (auto i : a) {
        ListNode *t = new ListNode(i);
        tail->next = t;
        tail = t;
    }
    return head->next;
}

void printL(ListNode *h)
{
    while (h) {
        std::cout << h->val << " ";
        h = h->next;
    }
    std::cout << std::endl;
}

bool equaList(ListNode *a, ListNode *b)
{
    while (a && b) {
        if (a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }
    return true;
}
