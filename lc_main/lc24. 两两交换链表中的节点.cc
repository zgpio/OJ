#include <lc/list.h>
#include <iostream>
using namespace std;

class Solution
{
   public:
    ListNode* swapPairs(ListNode* head)
    {
        ListNode hair(0);
        hair.next = head;
        ListNode* l = &hair;
        while (l->next && l->next->next) {
            ListNode* t = l->next->next;
            l->next->next = t->next;
            t->next = l->next;
            l->next = t;
            l = l->next->next;
        }
        return hair.next;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    ListNode* l = buildList({1, 2, 3, 4});
    ListNode* gt = buildList({2, 1, 4, 3});
    l = s.swapPairs(l);
    assert(equal_list(l, gt));
    return 0;
}
