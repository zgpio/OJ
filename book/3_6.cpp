#include <stdio.h>
#include <iostream>
using namespace std;

// 租赁游艇问题
const int N = 1000;
int r[N][N], m[N][N], s[N][N];
void dyna(int n)
{
    // 对角线更新表
    for (int d = 2; d < n; d++) {
        for (int i = 0; i < n - d; i++) {
            int j = i + d;
            for (int k = i + 1; k < j; k++) {
                int tmp = m[i][k] + m[k][j];
                if (tmp < m[i][j]) {
                    m[i][j] = tmp;
                    s[i][j] = k;
                }
            }
        }
    }
}
void print(int i, int j)
{
    if (s[i][j] == 0) {
        cout << j << " ";
        return;
    }
    print(i, s[i][j]);
    print(s[i][j], j);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input/3_6", "rt", stdin);
#endif
    int n;  // 共有 n 个站点
    cin >> n;
    // TODO 动态申请二维数组
    // 输入上三角矩阵
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            cin >> r[i][j];
            m[i][j] = r[i][j];
        }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << m[i][j] << " ";
        }
        std::cout << std::endl;
    }

    dyna(n);
    cout << m[0][n - 1] << endl;

    print(0, n - 1);
    cout << endl;
    return 0;
}
