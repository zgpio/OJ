// 最优服务次序问题
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    ifstream cin;
    cin.open("./input/4_6", ios::in);
    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n, std::greater<int>());  // 从大到小
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        // (i+1)个人等待了a[i]的时间
        sum += a[i]*(i+1);
        // a[i] *= i + 1;
    }
    // int sum = accumulate(a, a + n, 0);
    std::cout << sum * 1.0 / n << std::endl;
    return 0;
}
