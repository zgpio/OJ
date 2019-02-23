#include <algorithm>
#include <cassert>
#include <ctime>
#include <iostream>
using namespace std;

// QuickSort 非增序排序
// [begin, end)
template <typename T>
int partition(T a[], int begin, int end)
{
    int pivot = a[begin];
    while (begin < end) {
        while (begin < end && a[--end] >= pivot)
            ;
        a[begin] = a[end];
        while (begin < end && a[++begin] <= pivot)
            ;
        a[end] = a[begin];
    }
    a[begin] = pivot;
    return begin;
}

template <typename T>
void quickSort(T a[], int begin, int end)
{
    if (end - begin <= 1) return;
    int mid = partition(a, begin, end);

    quickSort(a, begin, mid);
    quickSort(a, mid + 1, end);
}

// 整合partition和quickSort
// [begin, end)
template <typename T>
void Qsort(T a[], int begin, int end)
{
    if (end - begin <= 1) return;
    int pivot = a[begin];
    int lp = begin, rp = end;
    while (lp < rp) {
        while (lp < rp && a[--rp] >= pivot)
            ;
        a[lp] = a[rp];
        while (lp < rp && a[++lp] <= pivot)
            ;
        a[rp] = a[lp];
    }
    assert(lp == rp);
    a[lp] = pivot;
    Qsort(a, begin, lp);
    Qsort(a, lp + 1, end);
}

inline int gen(int low, int high) { return rand() % (high - low + 1) + low; }
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int size = gen(4, 25);
    int *a = new int[size];
    int *b = new int[size];
    for (int i = 0; i < size; ++i) {
        b[i] = a[i] = gen(0, 100);
    }

    // quickSort(a, 0, size);
    Qsort(a, 0, size);
    sort(b, b + size);
    // 自动测试
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
        assert(a[i] == b[i]);
    }
    std::cout << std::endl;
    return 0;
}
