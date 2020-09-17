// ref to https://blog.csdn.net/wyf12138/article/details/53525742
#include <bits/stdc++.h>
using namespace std;

/*
问题描述
给出朋友关系，判断从指定人物出发能否通过双向朋友链抵达目标人物。

输入
第一行输入总人数n以及朋友关系数m, 人的编号从0到n-1。
接下来m行输入朋友关系，每个朋友关系占一行。
1个朋友关系包含s、t两个整数，表示s和t为朋友。
接下来一行输入查询数q。再接下来q行输入查询, 每个查询为两个整数s、t, 表示“从s能否抵达t？”

输出
如果从s出发能抵达t就输出yes，否则输出no，每个问题的回答占1行。

限制
1 < n < 100000, 0 < m < 100000, 1 < q < 10000

样例输入
10 9
0 1
0 2
3 4
5 7
5 6
6 7
6 8
7 8
8 9
3
0 1
5 9
1 3

样例输出
yes
yes
no
*/

const int MAX_N = 100000;

int n;
vector<int> G[MAX_N];
int color[MAX_N];
// 从结点r开始DFS,并填充颜色c
void dfs(int r, int c)
{
    color[r] = c;
    for (int i = 0; i < G[r].size(); i++) {
        int v = G[r][i];
        if (color[v] == -1) {
            dfs(v, c);  // 相邻结点v未填色，则继续搜索
        }
    }
}

void AssignColor()
{
    int id = 0;
    memset(color, -1, sizeof(color));  // 初始化color数组，-1表示未填色
    for (int u = 0; u < n; u++) {
        if (color[u] == -1)
            dfs(u, id++);  // 对未填色的结点开始DFS
    }
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("../input/求图的连通分量.txt", "rt", stdin);
#endif
    int m, s, t;

    while (cin >> n >> m) {
        // 创建邻接表
        for (int i = 0; i < m; i++) {
            cin >> s >> t;
            G[s].push_back(t);
            G[t].push_back(s);
        }
        // 填色开始
        AssignColor();

        int q;
        cin >> q;
        for (int i = 0; i < q; i++) {
            cin >> s >> t;
            if (color[s] == color[t]) {
                cout << "yes" << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }

    return 0;
}
