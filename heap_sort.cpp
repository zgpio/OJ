#include "lc/lc.h"
using namespace std;
// 数据结构与算法分析 - C语言描述
typedef int ElementType;
#define LeftChild(i) (2 * (i) + 1)
void PercDown(ElementType A[], int i, int N)
{
    int Child;
    ElementType Tmp;

    for (Tmp = A[i]; LeftChild(i) < N; i = Child) {
        Child = LeftChild(i);
        if (Child != N - 1 && A[Child + 1] > A[Child]) Child++;
        if (Tmp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = Tmp;
}

void Heapsort(ElementType A[], int N)
{
    int i;

    for (i = N / 2; i >= 0; i--) /* BuildHeap */
        PercDown(A, i, N);
    for (i = N - 1; i > 0; i--) {
        swap(A[0], A[i]); /* DeleteMax */
        PercDown(A, 0, i);
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
