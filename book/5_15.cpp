#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

int n, k;
int t[100086], s[100086];
int minc = 1000000;
bool ltt(int x, int y) { return x > y; }

inline void dfs(int i, int c)  // 当前费用c, 分配任务{i, ..., n}
{
    if (c >= minc) return;  // 剪枝
    if (i > n) {
        if (c < minc) minc = c;
        return;
    }
    for (int j = 1; j <= k; j++) {  // k machine
        if (s[j] + t[i] <= minc) {  // 剪枝
            s[j] += t[i];
            dfs(i + 1, max(c, s[j]));
            s[j] -= t[i];
        }
    }
    return;
}
int main()
{
    ifstream cin;
    cin.open("./input/5_15", ios::in);
    cin >> n >> k;
    memset(s, 0, sizeof(s));  // k个并行机器的时间费用
    for (int i = 1; i <= n; i++) cin >> t[i];
    sort(t + 1, t + n + 1, ltt);  // 从大到小排序可以更快接近最优解
    dfs(1, 0);
    cout << minc << endl;
    return 0;
}
