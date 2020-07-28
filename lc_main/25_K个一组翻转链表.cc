#include <iostream>
#include <lc/list.h>
using namespace std;

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (k == 1) return head;
        ListNode hair(0);
        hair.next = head;
        ListNode *l = &hair;
        int n = 0;
        while (l->next) {
            n++;
            l = l->next;
        }
        n /= k;
        int cnt = 1;
        l = &hair;
        // 将 head->next 指向的结点头插到子链表中
        while (head && head->next && n)
        {
            auto *t = head->next;
            head->next = head->next->next;
            t->next = l->next;
            l->next = t;
            cnt++;
            if (cnt == k) {
                l = head;
                head = head->next;
                cnt = 1;
                n--;
            }
        }
        return hair.next;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    {
        auto *l = s.reverseKGroup(buildList({1, 2, 3, 4, 5}), 2);
        auto *gt = buildList({2, 1, 4, 3, 5});
        printL(l);
        assert(equal_list(l, gt));
    }
    {
        auto *l = s.reverseKGroup(buildList({1, 2, 3, 4, 5}), 3);
        auto *gt = buildList({3, 2, 1, 4, 5});
        printL(l);
        assert(equal_list(l, gt));
    }

    return 0;
}
