#include "lc/lc.h"
#include "lc/list.h"
using namespace std;

class Solution {
public:
    ListNode *partition(ListNode *head, int x)
    {
        vector<int> before, after;
        while (head) {
            if (head->val < x)
                before.push_back(head->val);
            else
                after.push_back(head->val);
            head = head->next;
        }
        for (auto a : after)
            before.push_back(a);
        return buildList(before);
    }
};
int main()
{
    Solution sol;
    vector<int> t1 = {1, 4, 3, 2, 5, 2};
    int x1 = 3;
    vector<int> a1 = {1, 2, 2, 4, 3, 5};
    ListNode *test1 = buildList(t1);
    ListNode *ans1 = buildList(a1);
    ListNode *pred1 = sol.partition(test1, x1);
    while (pred1) {
        if (pred1->val != ans1->val) {
            std::cout << "assert fail!" << std::endl;
            break;
        }
        pred1 = pred1->next;
        ans1 = ans1->next;
    }

    return 0;
}