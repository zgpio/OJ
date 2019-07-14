#ifndef LCLIB
#define LCLIB
#include <vector>
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *buildList(std::vector<int> a);
void printL(ListNode *h);
bool equaList(ListNode *a, ListNode *b);

#endif /* ifndef LCLIB */
