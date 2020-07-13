#include <algorithm>
#include <iostream>
#include <lc/list.h>
#include <vector>
using namespace std;

// 使用相邻双指针解决有序重复元素问题
ListNode *deleteDuplicates(ListNode *head)
{
    if (head == nullptr) return nullptr;
    ListNode *i = head, *j = head->next;
    while (j) {
        if (i->val == j->val) {
            i->next = j->next;
            delete j;
            j = i->next;
        }
        else {
            i = i->next;
            j = j->next;
        }
    }
    return head;
}

int main(int argc, char *argv[])
{
    vector<pair<initializer_list<int>, initializer_list<int>>> cases = {
        {{1, 1, 2}, {1, 2}}, {{1, 1, 2, 3, 3}, {1, 2, 3}}};
    for (auto c : cases) {
        ListNode *l = buildList(c.first);
        printL(l);
        ListNode *rl = deleteDuplicates(l);
        printL(rl);
    }
    return 0;
}
