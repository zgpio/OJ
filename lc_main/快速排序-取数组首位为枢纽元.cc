#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 对于枢纽元而言, 分为以下四种情况:
// ┌─────┬──┬──────┐
// │  <  │🚩│  >=  │
// └─────┴──┴──────┘
// ┌─────┬──┬──────┐
// │  >  │🚩│  <=  │
// └─────┴──┴──────┘
// ┌──────┬──┬─────┐
// │  <=  │🚩│  >  │
// └──────┴──┴─────┘
// ┌──────┬──┬─────┐
// │  >=  │🚩│  <  │
// └──────┴──┴─────┘
// 特别注意: 当枢纽元两侧都不取等号, 可能造成死循环.

typedef int DataType;

void Qsort(DataType A[], int L, int R) // [L, R]
{
    if (L >= R) return;
    DataType pivot = A[L];
    int i = L, j = R;
    while (i < j) {
        while (i < j && A[j] >= pivot) j--;
        if (i < j) A[i] = A[j];
        while (i < j && A[i] < pivot) i++;
        if (i < j) A[j] = A[i];
    }
    A[i] = pivot;
    Qsort(A, L, i - 1);
    Qsort(A, i + 1, R);
}

int main(int argc, char *argv[])
{
    {
        int a[] = {1, 2, 3, 4, 5};
        const int N = sizeof(a) / sizeof(int);
        int *gt = new int[N];
        memcpy(gt, a, sizeof(int) * N);
        sort(gt, gt + N);
        do {
            // for (int i = 0; i < N; i++)
            //     cout << a[i] << " ";
            // cout << endl;
            int *v = new int[N];
            memcpy(v, a, sizeof(int) * N);
            Qsort(v, 0, N - 1);

            for (int i = 0; i < N; i++)
                assert(v[i] == gt[i]);

            delete[] v;
        } while (std::next_permutation(a, a + N));
        delete[] gt;
    }
    { // 当枢纽元两侧都不取等号, 此测试用例造成死循环.
        int a[] = {1, 1, 1, 1, 1};
        const int N = sizeof(a) / sizeof(int);
        Qsort(a, 0, N - 1);

        for (int i = 0; i < N; i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
