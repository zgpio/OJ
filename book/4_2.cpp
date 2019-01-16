#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
//头文件algorithm
// sort(数组名, 数组名+要排序的元素个数) 函数作用: 递增排序
// reverse(数组名, 数组名+要排序的元素个数) 函数作用: 逆置数组
// 最优合并问题
int main()
{
    ifstream cin;
    cin.open("./input/4_2", ios::in);
    int k;
    cin >> k;
    int* a = new int[k];
    int* b = new int[k];
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    cin.close();

    sort(a, a + k);
    int min_sum = 0;
    int left = 0;
    while (left < k - 1) {
        min_sum += a[left] + a[left + 1] - 1;
        a[left + 1] = a[left] + a[left + 1];
        //a[left] = 0;
        left++;
        sort(a + left, a + k);
    }

    sort(b, b + k, std::greater<int>());
    int max_sum = 0;
    left = 0;
    while (left < k - 1) {
        max_sum += b[left] + b[left + 1] - 1;
        b[left + 1] = b[left] + b[left + 1];
        //b[left] = 0;
        left++;
        sort(b + left, b + k, std::greater<int>());
    }

    cout << max_sum << " " << min_sum << endl;
    return 0;
}
