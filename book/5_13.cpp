#include <fstream>
#include <iostream>
using namespace std;

int n, cost = 0;
int x[100], c[100][100];

void work(int i, int count)
{
    if (i > n && count < cost) {
        cost = count;
        return;
    }
    if (count < cost)
        for (int j = 1; j <= n; j++)
            if (x[j] == 0) {
                x[j] = 1;
                work(i + 1, count + c[i][j]);
                x[j] = 0;
            }
}

int main()
{
    ifstream cinfile;
    cinfile.open("./input/5_13", ios::in);
    cinfile >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cinfile >> c[i][j];
            x[j] = 0;
        }
        cost += c[i][i];
    }
    work(1, 0);
    cout << cost << endl;
    return 0;
}
