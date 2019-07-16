#include "lc/lc.h"
#include "lc/list.h"
#include "lc/util.h"
using namespace std;

class Solution {
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (!head) return nullptr;
        ListNode *H = new ListNode(-1);
        H->next = head;
        ListNode *p = head->next;
        ListNode *prep = head;
        while (p) {
            ListNode *prei = H;
            ListNode *i = H->next;
            while (p->val > i->val) {
                prei = i;
                i = i->next;
            }
            // print("prei", prei->val, "i", i->val, "prep", prep->val, "p", p->val);
            // printL(H);
            if (i != p) {
                prep->next = p->next;
                p->next = i;
                prei->next = p;
                p = prep;
            }
            // print("prei", prei->val, "i", i->val, "prep", prep->val, "p", p->val);
            // printL(H);
            // print("---------");

            prep = p;
            p = p->next;
        }

        head = H->next;

        delete H;
        return head;
    }
};

int main()
{
    Solution sol;
    ListNode *t1 = buildList(vector<int>{4, 2, 1, 3});
    ListNode *a1 = buildList(vector<int>{1, 2, 3, 4});
    assert(equaList(a1, a1));
    assert(equaList(t1, t1));
    assert(equaList(sol.insertionSortList(t1), a1));

    ListNode *t2 = buildList(vector<int>{-1, 5, 3, 4, 0});
    ListNode *a2 = buildList(vector<int>{-1, 0, 3, 4, 5});
    assert(equaList(sol.insertionSortList(t2), a2));

    // test swapNode
    ListNode *t3 = buildList({-1, 1, 2, 3, 4, 5});
    // 5 <-> 1
    swapNode(t3, t3->next->next->next->next);
    printL(t3->next);

    // test insertNode
    ListNode *t4 = buildList({-1, 1, 2, 3, 4, 5});
    // 5插入到1前面
    insertNode(t4, t4->next->next->next->next);
    printL(t4->next);
    return 0;
}
