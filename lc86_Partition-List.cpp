#include <algorithm>
#include <assert.h>
#include <climits>
#include <cstdio>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *conv(vector<int> a)
{
    ListNode *head = new ListNode(-1);
    ListNode *tail = head;
    for (auto i : a) {
        ListNode *t = new ListNode(i);
        tail->next = t;
        tail = t;
    }
    return head->next;
}
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
        return conv(before);
    }
};
int main()
{
    Solution sol;
    vector<int> t1 = {1, 4, 3, 2, 5, 2};
    int x1 = 3;
    vector<int> a1 = {1, 2, 2, 4, 3, 5};
    ListNode *test1 = conv(t1);
    ListNode *ans1 = conv(a1);
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
