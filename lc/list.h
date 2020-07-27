#ifndef LCLIB
#define LCLIB
#include <vector>
#include <cassert>
#include <cstddef>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL)
    {
    }
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

/// 将结点j插入到结点i前
///
/// NOTE: 断言链表有头结点
/// @param prei   结点i的前驱
/// @param prej   结点j的前驱
inline void insertNode(ListNode *prei, ListNode *prej)
{
    assert(prei && prej && prei->next && prej->next);
    ListNode *i = prei->next;
    ListNode *j = prej->next;

    prej->next = j->next;
    j->next = i;
    prei->next = j;
}

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

ListNode *buildList(std::vector<int> a);
void printL(ListNode *h);
bool equal_list(ListNode *a, ListNode *b);

#endif /* ifndef LCLIB */
