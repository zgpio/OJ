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

inline int gen(int low, int high) { return rand() % (high - low + 1) + low; }
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int size = gen(4, 25);
    int *a = new int[size];
    for (int i = 0; i < size; ++i) a[i] = gen(0, 100);

    quickSort(a, 0, size);
    for (int i = 0; i < size; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
