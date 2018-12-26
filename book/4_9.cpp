// 汽车加油
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream cin;
    cin.open("./input/4_9", ios::in);
    int n, k;
    cin >> n >> k;
    int* a = new int[k + 1];
    for (int i = 0; i < k + 1; ++i) cin >> a[i];

    int left = n, cnt = 0;
    for (int i = 0; i < k + 1; ++i) {
        if (a[i] > n) {
            std::cout << "No Solution" << std::endl;
            return 0;
        }
        else if (a[i] > left) {
            cnt++;
            left = n - a[i];
        }
        else {
            left -= a[i];
        }
    }
    std::cout << cnt << std::endl;

    return 0;
}
