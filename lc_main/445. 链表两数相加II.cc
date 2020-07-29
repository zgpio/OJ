#include <lc/list.h>
#include <iostream>
#include <stack>
using namespace std;

class Solution
{
   public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int f = 0;
        ListNode *sum = nullptr;
        while (!s1.empty() || !s2.empty() || f) {
            int a = 0, b = 0;
            if (!s1.empty()) {
                a = s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                b = s2.top();
                s2.pop();
            }
            int s = a + b + f;
            if (s >= 10) {
                f = 1;
                s -= 10;
            } else
                f = 0;
            ListNode *t = new ListNode(s);
            t->next = sum;
            sum = t;
        }
        return sum;
    }
    // 数位是反向存放的链表求和
    ListNode *addTwoNumbersI(ListNode *l1, ListNode *l2)
    {
        int f = 0;
        ListNode hair(0);
        ListNode *tail = &hair;
        while (l1 || l2 || f) {
            int a = 0, b = 0;
            if (l1) {
                a = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                b = l2->val;
                l2 = l2->next;
            }
            int s = a + b + f;
            if (s >= 10) {
                f = 1;
                s -= 10;
            } else
                f = 0;
            ListNode *t = new ListNode(s);
            tail->next = t;
            tail = tail->next;
        }
        return hair.next;
    }
};

int main(int argc, char *argv[])
{
    Solution s;

    {
        ListNode *l1 = buildList({7, 2, 4, 3});
        ListNode *l2 = buildList({5, 6, 4});
        ListNode *suml = s.addTwoNumbers(l1, l2);
        ListNode *gt = buildList({7, 8, 0, 7});
        assert(equal_list(gt, suml));
    }
    {
        ListNode *l1 = buildList({5});
        ListNode *l2 = buildList({5});
        ListNode *suml = s.addTwoNumbers(l1, l2);
        ListNode *gt = buildList({1, 0});
        assert(equal_list(gt, suml));
    }
    // test addTwoNumbersI
    {
        ListNode *l1 = buildList({7, 2, 4, 3});
        ListNode *l2 = buildList({5, 6, 4});
        ListNode *suml = s.addTwoNumbersI(l1, l2);
        printL(suml);
        ListNode *gt = buildList({2, 9, 8, 3});
        assert(equal_list(suml, gt));
    }

    return 0;
}
