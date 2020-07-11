#include <iostream>
#include "lc/list.h"
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
        if (pHead==nullptr || pHead->next==nullptr)
            return pHead;
        ListNode *newHead = ReverseListRecursive(pHead->next);
        pHead->next->next = pHead;
        pHead->next = nullptr;
        return newHead;
    }
};

int main()
{
    Solution s;
    assert(s.ReverseList(NULL)==NULL);
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


    return 0;
}
