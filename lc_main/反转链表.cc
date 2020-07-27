#include "lc/list.h"
#include <stack>
#include <iostream>
using namespace std;

//   pHead          p            pn
//                             
// ┌───┬────┐   ┌───┬────┐   ┌───┬────┐
// │val│next│──▶│val│next│──▶│val│next│──▶NULL
// └───┴────┘   └───┴────┘   └───┴────┘
class Solution {
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL) {
            return NULL;
        }

        // 将链表分割为第一个结点和子链表，分别由pHead、p指向
        ListNode *p = pHead->next;
        pHead->next = NULL;

        while (p != NULL) {
            ListNode *pn = p->next; // 保存下一个结点的地址

            p->next = pHead;
            pHead = p;
            p = pn;
        }

        return pHead;
    }
    ListNode *ReverseListRecursive(ListNode *pHead)
    {
        if (pHead == nullptr || pHead->next == nullptr) return pHead;
        ListNode *newHead = ReverseListRecursive(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return newHead;
    }
};

// 92. 反转链表 II
ListNode *reverseBetween(ListNode *head, int m, int n)
{
    ListNode hair(0);
    hair.next = head;
    ListNode *l = &hair;
    int cnt = n - m;
    while (l->next && --m) {
        l = l->next;
    }
    if (!l->next) return hair.next;
    ListNode *tail = l->next;
    while (cnt-- && tail->next) {
        ListNode *t = tail->next;
        tail->next = tail->next->next;
        t->next = l->next;
        l->next = t;
    }
    return hair.next;
}

// 使用栈, 空间复杂度不是O(1)
ListNode *reverseBetween2(ListNode *head, int m, int n)
{
    ListNode *h = head;
    stack<int> s;
    int cnt = m;
    while (--cnt)
        h = h->next;
    ListNode *p = h;
    cnt = n - m + 1;
    while (cnt--) {
        s.push(p->val);
        p = p->next;
    }
    while (!s.empty()) {
        h->val = s.top();
        h = h->next;
        s.pop();
    }

    return head;
}
int main()
{
    Solution s;
    assert(s.ReverseList(NULL) == NULL);
    {
        ListNode *list = buildList({1, 2, 3, 4, 5});
        printL(list);
        ListNode *rlist = s.ReverseList(list);
        printL(rlist);
    }
    {
        ListNode *list = buildList({1, 2, 3, 4, 5});
        printL(list);
        ListNode *rlist = s.ReverseListRecursive(list);
        printL(rlist);
    }
    {
        ListNode *list = buildList({1, 2, 3, 4, 5});
        printL(list);
        ListNode *rlist = reverseBetween(list, 2, 4);
        printL(rlist);
    }
    {
        ListNode *list = buildList({5});
        printL(list);
        ListNode *rlist = reverseBetween(list, 1, 1);
        printL(rlist);
    }
    {
        ListNode *test = buildList({1, 2, 3, 4, 5});
        int m = 2, n = 4;
        ListNode *ans = buildList({1, 4, 3, 2, 5});

        printL(test);
        ListNode *pred = reverseBetween2(test, m, n);
        equaList(ans, pred);
        printL(pred);
    }

    return 0;
}
