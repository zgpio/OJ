#include <fstream>
#include <iostream>
using namespace std;
// 工作分配问题
int n, cost;
int f[100], c[100][100];

void work(int i, int base)  // 分配第i~n件工作, 当前费用是base
{
    if (i > n && base < cost) {
        cost = base;
        return;
    }
    if (base < cost)
        for (int j = 1; j <= n; j++)
            if (f[j] == 0) {  // 如果工人j空闲
                f[j] = 1;
                work(i + 1, base + c[i][j]);
                f[j] = 0;
            }
}

int main()
{
    ifstream cin;
    cin.open("./input/5_13", ios::in);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
        f[i] = 0;         // 标记工人是否空闲
        cost += c[i][i];  // cost init
    }
    work(1, 0);
    cout << cost << endl;
    return 0;
}
