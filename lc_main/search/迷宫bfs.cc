#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int go[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};  //四个方向
int pre[10000];                                     //用来寻找父亲节点
bool vis[10][10];                                   //标记数组
struct node {
    int x, y, s;
};  //存储坐标信息及当前步数
int bfs(vector<vector<int>> &map, node s, node e)
{
    memset(vis, 0, sizeof(vis));
    const int n = map.size();
    const int m = map[0].size();
    node now{s.x, s.y, 0};
    queue<node> q;      //创建队列
    vis[s.x][s.y] = 1;  //走过的标记为1
    q.push(now);        //加入队首
    while (!q.empty()) {
        now = q.front();
        if (now.x == e.x && now.y == e.y)
            return now.s;  //满足条件时返回走过的步数
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = now.x + go[i][0];
            int yy = now.y + go[i][1];
            if (xx >= 0 && yy >= 0 && xx < n && yy < m && map[xx][yy] == 0 && vis[xx][yy] == 0)  //判断是否越界
            {
                vis[xx][yy] = 1;                       //标记走过的
                pre[xx * n + yy] = now.x * n + now.y;  //存储坐标, 转化成一维形式
                q.push({xx, yy, now.s + 1});
            }
        }
    }
    return 0;
}
void myprint(int n)
{
    // printf("pre[%d]=(%d)\n",n,pre[n]);
    if (n == pre[n])
        return;
    myprint(pre[n]);  //寻找父亲节点
    printf("(%d, %d)\n", n / 5, n % 5);
}  //回溯打印路径
int main()
{
    // clang-format off
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
    };
    // clang-format on
    const int n = maze.size();
    node s{0, 0}, e{4, 4};
    if (bfs(maze, s, e)) {
        printf("(0, 0)\n");      //先打印起点(0, 0)
        myprint(e.x * n + e.y);  //从终点(4, 4)开始回溯
    } else
        printf("-1\n");
    return 0;
}
