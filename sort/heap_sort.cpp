#include "lc/lc.h"
using namespace std;
// 数据结构与算法分析 - C语言描述
typedef int ElementType;
#define LeftChild(i) (2 * (i) + 1)
// 下滤a[i]
void PercDown(ElementType a[], int i, int n)
{
    int child;
    ElementType tmp;

    for (tmp = a[i]; LeftChild(i) < n; i = child) {
        child = LeftChild(i);
        if (child != n - 1 && a[child + 1] > a[child]) child++;
        if (tmp < a[child])
            a[i] = a[child];
        else
            break;
    }
    a[i] = tmp;
}

void Heapsort(ElementType a[], int n)
{
    int i;

    for (i = n / 2; i >= 0; i--) // BuildHeap
        PercDown(a, i, n);
    for (i = n - 1; i > 0; i--) {
        swap(a[0], a[i]); // DeleteMax
        PercDown(a, 0, i);
    }
}

int main(int argc, char *argv[])
{
    ElementType a[] = {3, 1, 2, 4, 6, 5};
    Heapsort(a, 6);
    for (int i = 0; i < 6; i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}
