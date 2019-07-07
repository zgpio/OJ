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
using namespace std;

#define MAX 20

// TODO: 组合数生成测试, 题目还没有做完
// c(r,n)
// k1为当前已记录序列长度, k2为剩余待选取元素的起始位置
int rec[MAX]; // 记录组合序列
int cnt;
void combination_recursive(int arr[], int n, int r, int k1, int k2)
{
    cnt++;
    if (k1 == r) // 输出当前序列
    {
        for (int i = 0; i < r; ++i)
            cout << rec[i] << " ";
        cout << endl;
    }
    else
        for (int i = k2; i + r - k1 - 1 < n; ++i) {
            rec[k1] = arr[i];                                // 子序列赋值
            combination_recursive(arr, n, r, k1 + 1, i + 1); // 递归回溯
        }
}
void combination(int arr[], int n) // 输出n个元素的全部组合
{
    for (int i = 0; i <= n; ++i)
        combination_recursive(arr, n, i, 0, 0);
}

int main()
{
    int a[] = {0, 1, 2, 3, 4, 5, 6};
    int len = sizeof(a) / sizeof(a[0]);
    combination(a, len);
    std::cout << cnt << std::endl;

    return 0;
}
