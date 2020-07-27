#include "list.h"
#include <iostream>
#include <vector>
ListNode *buildList(std::vector<int> a)
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

bool equal_list(ListNode *a, ListNode *b)
{
    while (a && b) {
        if (a->val != b->val) return false;
        a = a->next;
        b = b->next;
    }
    if (a == NULL && b == NULL)
        return true;
    else
        return false;
}
