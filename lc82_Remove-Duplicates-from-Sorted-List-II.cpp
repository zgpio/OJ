#include "lc/lclib.h"
#include "lc/lc.h"
using namespace std;

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *H = new ListNode(-1);
        H->next = head;
        ListNode *pre = H;
        ListNode *cur = head;
        while (cur && cur->next) {
            ListNode *c = cur;
            ListNode *cn = cur->next;
            ListNode *cnn = cur->next->next;
            if (c->val == cn->val) {
                if (cnn && c->val == cnn->val) {
                    delete c;
                    pre->next = cn;
                    cur = cn;
                }
                else {
                    delete cn;
                    delete c;
                    pre->next = cnn;
                    cur = cnn;
                }
            }
            else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return H->next;
    }
};

int main()
{
    Solution sol;
    ListNode *t1 = conv({1, 2, 3, 3, 4, 4, 5});
    ListNode *a1 = conv({1, 2, 5});
    ListNode *t2 = conv({1, 1, 1, 2, 3});
    ListNode *a2 = conv({2, 3});
    assert(equaList(t1, t1));
    assert(equaList(sol.deleteDuplicates(t1), a1));
    assert(equaList(sol.deleteDuplicates(t2), a2));
    return 0;
}
