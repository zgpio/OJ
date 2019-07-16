#ifndef LCLIB
#define LCLIB
#include <vector>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 断言链表有头结点
inline void swapNode(ListNode *prei, ListNode *prej)
{
    assert(prei && prei->next && prej && prej->next);
    ListNode *i = prei->next;
    ListNode *j = prej->next;
    prei->next = j;
    prej->next = i;
    ListNode *t = i->next;
    i->next = j->next;
    j->next = t;
}

ListNode *buildList(std::vector<int> a);
void printL(ListNode *h);
bool equaList(ListNode *a, ListNode *b);

#endif /* ifndef LCLIB */
