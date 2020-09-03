#include "lc/lc.h"
#include "lc/list.h"

class Solution
{
   public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (k-- && fast != nullptr) {
            fast = fast->next;
        }
        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    {
        ListNode *l = buildList({1, 2, 3, 4, 5});
        assert(s.getKthFromEnd(l, 2) == l->next->next->next);
    }
    {
        ListNode *l = buildList({});
        assert(s.getKthFromEnd(l, 2) == nullptr);
    }
    {
        ListNode *l = buildList({1, 2, 3});
        assert(s.getKthFromEnd(l, 4) == l);
    }
    return 0;
}
