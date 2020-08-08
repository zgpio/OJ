#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/*********************************************************************
HDU 3765 Celebrity Split
题意:
n件物品各有价格vi, 两个人分这些物品, 要使每人分得的总价值相等,
不能满足要求的物品拿去卖再分, 问拿去卖的物品的最小总价值
思路:
n不超过20, DFS(n层3叉搜索树)+剪枝应该可行, 每个物品要么给A要么给B要么拿去卖
只能说数据太弱, 没有剪枝就能AC
**********************************************************************/
const int N = 30;
int a[N];                      // 记录每件物品的价值
int res;                       // 记录两人分走的物品的价值
int n;                         // n件物品
void dfs(int i, int A, int B)  // i是当前要分的房子的编号, A是A拿走的价值, B是B拿走的价值
{
    if (i > n)
        return;
    if (A == B)  // 可以平分价值
    {
        if (A + B > res)
            res = A + B;
    }
    dfs(i + 1, A, B);         // 拿去卖
    dfs(i + 1, A + a[i], B);  // 给A
    dfs(i + 1, A, B + a[i]);  // 给B
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("../../input/平分问题", "rt", stdin);
#endif
    while (cin >> n) {
        if (!n)
            break;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }
        res = 0;
        dfs(0, 0, 0);
        printf("%d\n", sum - res);
    }
    return 0;
}
