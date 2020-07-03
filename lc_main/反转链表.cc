#include <iostream>
using namespace std;

struct ListNode {
public:
    int val;
    struct ListNode *next;
};

//   pHead          p            pn
//                             
// ┌───┬────┐   ┌───┬────┐   ┌───┬────┐
// │val│next│──▶│val│next│──▶│val│next│──▶NULL
// └───┴────┘   └───┴────┘   └───┴────┘
class Solution {
public:
    ListNode *ReverseList(ListNode *pHead)
    {
        if (pHead == NULL) {
            return NULL;
        }

        ListNode *p = pHead->next;
        pHead->next = NULL;

        cout << pHead->val << " in list head now..." << endl;

        ListNode *pn = NULL;
        while (p != NULL) {
            pn = p->next; // 保存下一个结点的地址

            p->next = pHead;
            pHead = p;
            p = pn;

            cout << pHead->val << " in list head now..." << endl;
        }

        return pHead;
    }
};

int main()
{
    ListNode list[5];
    list[0].val = 1; list[0].next = &list[1];
    list[1].val = 2; list[1].next = &list[2];
    list[2].val = 3; list[2].next = &list[3];
    list[3].val = 4; list[3].next = &list[4];
    list[4].val = 5; list[4].next = NULL;

    ListNode *node = list;
    while (node != NULL) {
        cout << node->val;
        node = node->next;
    }
    cout << endl;

    Solution solu;
    assert(solu.ReverseList(NULL)==NULL);
    node = solu.ReverseList(list);
    while (node != NULL) {
        cout << node->val;
        node = node->next;
    }
    cout << endl;

    return 0;
}
