#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

struct node {
    int x, y;
};  //存坐标

class Solution
{
   public:
    int solve(vector<vector<int>> maze, const node s, const node e)
    {
        ex_ = e.x;
        ey_ = e.y;
        n = maze.size();
        m = maze[0].size();
        map = maze;
        memset(vis, 0, sizeof(vis));  //初始化标记数组
        min_ = INT_MAX;
        path.clear();  //清空
        dfs(s.x, s.y, 0);
        if (min_ == INT_MAX)
            printf("-1\n");
        else {
            printf("%d\n", min_);
            for (int i = 0; i <= min_; i++)
                printf("(%d, %d)\n", ans[i].x, ans[i].y);  //输出结果
        }
        return min_;
    }

   private:
    void dfs(int x, int y, int step)
    {
        path.push_back({x, y});    //压入坐标
        if (x == ex_ && y == ey_)  //当搜索到终点时
        {
            if (step < min_) {
                min_ = step;  //更新最小的步数
                ans = path;
            }
        } else {
            for (int i = 0; i < 4; i++) {
                int xx = x + go[i][0], yy = y + go[i][1];
                if (0 <= xx && xx < n && 0 <= yy && yy < m && map[xx][yy] == 0 && vis[xx][yy] == 0)  //判断是否越界
                {
                    vis[xx][yy] = 1;        //走过的标记为1
                    dfs(xx, yy, step + 1);  //搜索下一层
                    vis[xx][yy] = 0;        //标记回来，以便下次搜索
                }
            }
        }
        path.pop_back();  //弹出坐标
    }
    vector<vector<int>> map;
    int n, m;  // n行m列, x索引行, y索引列
    int ex_, ey_;
    int min_;
    int go[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};  //四个方向
    bool vis[100][100];                                 //标记数组
    vector<node> path;                                  //用来存储路径
    vector<node> ans;                                   //存储反过来后路径
};

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
    Solution s;
    s.solve(maze, {0, 0}, {4, 4});
    // (0, 0) (1, 0) (2, 0) (2, 1) (2, 2) (2, 3) (2, 4) (3, 4) (4, 4)

    return 0;
}
