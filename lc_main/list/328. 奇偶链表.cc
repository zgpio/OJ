#include <lc/list.h>
#include <iostream>
using namespace std;

class Solution
{
   public:
    // 86. Partition-List 的变种, 类似于快速排序分区
    ListNode *oddEvenList(ListNode *head)
    {
        ListNode *tail = head;
        ListNode *p = head;
        while (p && p->next && p->next->next) {
            ListNode *t = p->next->next;
            p->next->next = t->next;
            t->next = tail->next;
            tail->next = t;
            if (tail == p)
                p = p->next->next;
            else
                p = p->next;
            tail = tail->next;
        }
        return head;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    {
        ListNode *l = buildList({1, 2, 3, 4, 5});
        ListNode *pred = s.oddEvenList(l);
        printL(pred);
        ListNode *gt = buildList({1, 3, 5, 2, 4});
        assert(equal_list(pred, gt));
    }
    {
        ListNode *l = buildList({2, 1, 3, 5, 6, 4, 7});
        ListNode *pred = s.oddEvenList(l);
        printL(pred);
        ListNode *gt = buildList({2, 3, 6, 7, 1, 5, 4});
        assert(equal_list(pred, gt));
    }
    return 0;
}
