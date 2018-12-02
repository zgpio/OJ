// 汽车加油
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
    ifstream cinfile;
    cinfile.open("./input/4_9", ios::in);
    int n, k;
    cinfile >> n >> k;
    int* a = new int[k + 1];
    for (int i = 0; i < k + 1; ++i) {
        cinfile >> a[i];
    }
    int sum = 0, cnt = 0;
    for (int i = 0; i < k + 1; ++i) {
        if (a[i] > n) {
            std::cout << "No Solution" << std::endl;
            return 0;
        }
        if (sum + a[i] > n) {
            cnt++;
            sum = a[i];
        }
        else {
            sum += a[i];
        }
    }
    std::cout << cnt << std::endl;

    return 0;
}
