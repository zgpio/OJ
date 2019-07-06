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
#include "lc/lclib.h"
using namespace std;

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL) return head;
        deque<int> dq;
        ListNode *h = head;
        int cnt = 0;
        while (h) {
            cnt++;
            dq.push_back(h->val);
            h = h->next;
        }
        k = k % cnt;
        while (k--) {
            int t = dq.back();
            dq.pop_back();
            dq.push_front(t);
        }
        h = head;
        while (h) {
            h->val = dq.front();
            dq.pop_front();
            h = h->next;
        }
        return head;
    }
};

int main()
{
    Solution sol;
    vector<int> t1 = {1, 2, 3, 4, 5};
    vector<int> a1 = {4, 5, 1, 2, 3};
    vector<int> t2 = {};
    int k2 = 1;
    vector<int> t3 = {1, 2, 3};
    int k3 = 2000000000;

    int k1 = 2;
    ListNode *test1 = conv(t1);
    printL(test1);
    // ListNode* ans1 = conv(a1);
    ListNode *ans1 = sol.rotateRight(test1, k1);
    printL(ans1);
    ListNode *test2 = conv(t2);
    ListNode *ans2 = sol.rotateRight(test2, k2);

    ListNode *test3 = conv(t3);
    ListNode *ans3 = sol.rotateRight(test3, k3);
    printL(ans3);

    return 0;
}
