#include "lc/lc.h"
#include "lc/list.h"
using namespace std;

// h
// 
// * ──▶ 3 ──▶ 1 ──▶ 2 ──▶ NIL
// 
// t
// 维护tail指针, 指向小于x的链表的尾结点
// 用head->next遍历链表

class Solution
{
   public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode hair(0);
        hair.next = head;
        ListNode *tail = &hair;
        head = tail;
        while (head->next) {
            if (head->next->val < x) {
                if (head == tail) {
                    head = head->next;
                } else {
                    ListNode *t = head->next;
                    head->next = t->next;
                    t->next = tail->next;
                    tail->next = t;
                }
                tail = tail->next;
            } else
                head = head->next;
        }
        return hair.next;
    }
};
int main()
{
    Solution sol;
    {
        int x = 3;
        ListNode *test = buildList({3, 1, 2});
        ListNode *ans = buildList({1, 2, 3});
        ListNode *pred = sol.partition(test, x);
        printL(pred);
        assert(equal_list(pred, ans));
    }
    {
        int x = 3;
        ListNode *test = buildList({1, 4, 3, 2, 5, 2});
        ListNode *ans = buildList({1, 2, 2, 4, 3, 5});
        ListNode *pred = sol.partition(test, x);
        printL(pred);
        assert(equal_list(pred, ans));
    }
    {
        int x = 2;
        ListNode *test = buildList({1, 1});
        ListNode *ans = buildList({1, 1});
        ListNode *pred = sol.partition(test, x);
        printL(pred);
        assert(equal_list(pred, ans));
    }

    return 0;
}
