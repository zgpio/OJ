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
#include <stack>
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
void printL(ListNode *l)
{
    while (l) {
        std::cout << l->val << " ";
        l = l->next;
    }
    std::cout << std::endl;
}

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

ListNode *conv(vector<int> a)
{
    ListNode *head = new ListNode(-1);
    ListNode *tail = head;
    for (auto i : a) {
        ListNode *t = new ListNode(i);
        tail->next = t;
        tail = tail->next;
    }
    return head->next;
}
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
