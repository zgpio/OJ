#include "lc/lc.h"
#include "lc/lclib.h"
using namespace std;

class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n)
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
};

int main()
{
    Solution sol;
    vector<int> t1 = {1, 2, 3, 4, 5};
    vector<int> a1 = {1, 4, 3, 2, 5};
    ListNode *test1 = conv(t1);
    int m = 2, n = 4;
    ListNode *ans1 = conv(a1);

    ListNode *pred1 = sol.reverseBetween(test1, m, n);
    printL(pred1);
    while (ans1) {
        if (ans1->val != pred1->val) {
            std::cout << "Assert fail!" << std::endl;
            break;
        }
        else
            std::cout << ans1->val << " ";
        ans1 = ans1->next;
        pred1 = pred1->next;
    }
    std::cout << std::endl;
    return 0;
}
