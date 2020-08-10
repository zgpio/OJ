#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// HDU 1242 Rescue
// 题意: 要求天使的朋友在最短的时间内救出天使, a代表天使, r代表天使的朋友(可能有多个), .代表路, #代表墙, x代表小兵,
// 每走一步需要一个时间, 打败小兵要一个时间, 移到小兵的位置要一个时间;
// 如果能救出, 输出最短的时间.

int go[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};  // 四个方向
int pre[200][200];                                  // 用来寻找父亲节点
bool vis[200][200];                                 // 标记数组
int ex, ey;                                         // 终点全局变量
struct node {
    int x, y, s;
    bool operator<(const node a) const
    {
        return s > a.s;  // 从小到大排序
    }
};  // 存储坐标信息及当前步数

int bfs(vector<vector<char>> &map, node s, vector<node> ev)
{
    memset(vis, 0, sizeof(vis));
    const int n = map.size();
    const int m = map[0].size();
    node now{s.x, s.y, 0};
    priority_queue<node> q;         // 创建队列
    pre[s.x][s.y] = s.x * m + s.y;  // 起点的上一个位置设置为自身
    vis[s.x][s.y] = 1;              // 走过的标记为1
    q.push(now);                    // 加入队首
    while (!q.empty()) {
        now = q.top();
        for (auto e : ev) {
            if (now.x == e.x && now.y == e.y) {
                ex = e.x, ey = e.y;
                return now.s;  // 满足条件时返回走过的步数
            }
        }
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = now.x + go[i][0];
            int yy = now.y + go[i][1];
            if (xx >= 0 && yy >= 0 && xx < n && yy < m && map[xx][yy] != '#' && vis[xx][yy] == 0) {
                vis[xx][yy] = 1;                  // 标记走过的
                pre[xx][yy] = now.x * m + now.y;  // 存储坐标, 转化成一维形式
                if (map[xx][yy] == 'x')
                    q.push({xx, yy, now.s + 2});
                else
                    q.push({xx, yy, now.s + 1});
            }
        }
    }
    return 0;
}
// 回溯打印路径
void myprint(int x, int y, int m)
{
    // printf("pre[%d]=(%d)\n",n,pre[n]);
    if (x * m + y == pre[x][y])  // 如果是起点
        return;
    int px = pre[x][y] / m, py = pre[x][y] % m;
    myprint(px, py, m);  // 寻找父亲节点
    printf("(%d, %d)\n", px, py);
}
int main()
{
#ifdef LOCAL_JUDGE
    freopen("../../input/迷宫救援.txt", "rt", stdin);
#endif
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        getchar();
        vector<vector<char>> maze(n, vector<char>(m));
        node s;
        vector<node> ev;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%c", &maze[i][j]);
                if (maze[i][j] == 'a') {
                    s.x = i, s.y = j;
                } else if (maze[i][j] == 'r') {
                    ev.push_back({i, j});
                }
            }
            getchar();
        }

        int len = bfs(maze, s, ev);
        if (len) {
            printf("%d\n", len);
            myprint(ex, ey, m);            // 从终点开始回溯
            printf("(%d, %d)\n", ex, ey);  // 打印终点
        } else {
            printf("Poor ANGEL has to stay in the prison all his life.\n");
        }
    }
    return 0;
}
