#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;
//头文件algorithm
// sort(数组名, 数组名+要排序的元素个数) 函数作用: 递增排序
// reverse(数组名, 数组名+要排序的元素个数) 函数作用: 逆置数组
int main()
{
    ifstream cinfile;
    cinfile.open("./input/4_2", ios::in);
    int k;
    cinfile >> k;
    int* a = new int[k];
    int* b = new int[k];
    for (int i = 0; i < k; i++) {
        cinfile >> a[i];
        b[i] = a[i];
    }
    cinfile.close();

    sort(a, a + k);

    int min_sum = 0;
    int min_mark = 0;
    while (min_mark < k - 1) {
        min_sum += a[min_mark] + a[min_mark + 1] - 1;
        a[min_mark] = a[min_mark] + a[min_mark + 1];
        a[min_mark + 1] = 0;
        min_mark++;
        sort(a, a + k);
    }

    sort(b, b + k);
    int max_sum = 0;
    for (int hh = 1; hh <= k - 1; hh++) {
        max_sum += b[k - 1] + b[k - 2] - 1;
        b[k - 1] = b[k - 1] + b[k - 2];
        b[k - 2] = 0;
        sort(b, b + k);
    }
    cout << max_sum << " ";
    cout << min_sum << endl;
    return 0;
}
