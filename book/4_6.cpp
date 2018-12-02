// 最优服务次序问题
#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
using namespace std;

int main()
{
    ifstream cinfile;
    cinfile.open("./input/4_6", ios::in);
    int n;
    cinfile >> n;
    int* a = new int[n];
    for (int i = 0; i < n; ++i) {
        cinfile >> a[i];
    }
    sort(a, a + n, std::greater<int>());
    for (int i = 0; i < n; ++i) {
        a[i] *= i + 1;
    }
    int sum = accumulate(a, a + n, 0);
    std::cout << sum * 1.0 / n << std::endl;
    return 0;
}
