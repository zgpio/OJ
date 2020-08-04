#include <iostream>
#include <lc/list.h>
using namespace std;

class Solution {
public:
    // 题解: 快慢指针法, 快指针走两步, 慢指针走一步, 找到链表的中点.
    //       然后, 翻转后半部分. 最后从头、中点开始判断是否相同. 恢复链表的步骤省略.
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next) return true;
        ListNode *fast = head, *slow = head, *pre = nullptr;
        // 1、找到链表的中点, 链表长度 1)奇数: slow指向中间 2)偶数: slow指向中间偏右
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // 2、将slow指向的子链表转移到pre指向的空链表,
        //    最后翻转完成之后pre指向反转链表的头节点
        while (slow) {
            ListNode *p = slow->next;
            slow->next = pre;
            pre = slow;
            slow = p;
        }
        // 3、前后链表进行比较, 注意若为奇数链表, 后半部分回比前部分多一个节点,
        //    然而我们只比较相同长度的节点值, 巧妙地避开这点判断
        while (head && pre) {
            if (head->val != pre->val) return false;
            head = head->next;
            pre = pre->next;
        }
        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    {
        ListNode *l = buildList({1, 2, 3, 5, 3, 2, 1});
        assert(s.isPalindrome(l) == true);
    }
    {
        ListNode *l = buildList({1, 2, 3, 3, 2, 1});
        assert(s.isPalindrome(l) == true);
    }
    {
        ListNode *l = buildList({});
        assert(s.isPalindrome(l) == true);
    }
    {
        ListNode *l = buildList({1, 2});
        assert(s.isPalindrome(l) == false);
    }
    return 0;
}
