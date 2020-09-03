#include <bits/stdc++.h>
#include "lc/list.h"
using namespace std;

class Solution {
public:
    /// 计算链表长度
    inline int listLen(ListNode *p)
    {
        assert(p);
        int n = 0;
        while (p) {
            n++;
            p = p->next;
        }
        return n;
    }
    void reorderList(ListNode *head)
    {
        if (!head || !head->next) return;
        int n = listLen(head);
        int cnt = (n - 1) / 2;
        ListNode *p = head;
        // 找到第二部分的前驱结点
        while (cnt--) {
            p = p->next;
        }
        ListNode *l2 = p->next;
        p->next = nullptr;
        l2 = reverseList(l2);

        p = head;
        while (l2) {
            ListNode *t = l2;
            ListNode *pa = p->next;
            l2 = l2->next;
            p->next = t;
            t->next = pa;
            p = pa;
        }
    }
    // 无头结点
    inline ListNode *reverseList(ListNode *p)
    {
        ListNode *h = new ListNode(-1);
        h->next = p;
        while (p->next) {
            insertNode(h, p);
        }
        ListNode *ret = h->next;
        delete h;
        return ret;
    }
};

int main()
{
    Solution sol;
    ListNode *t1 = buildList({1, 2, 3, 4});
    ListNode *a1 = buildList({1, 4, 2, 3});
    sol.reorderList(t1);
    printL(t1);

    ListNode *t2 = buildList({1, 2, 3, 4, 5});
    ListNode *a2 = buildList({1, 5, 2, 4, 3});
    sol.reorderList(t2);
    printL(t2);

    return 0;
}
