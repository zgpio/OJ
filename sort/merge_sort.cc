#include <cstdio>

// 打印结果
void Show(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

// 归并排序中的合并算法, 合并a[l, m]与a[m+1, r]
void Merge(int a[], int l, int m, int r)
{
    const int len = r - l + 1;
    int aux[len];  // 临时数组 (若不使用临时数组, 将两个有序数组合并为一个有序数组比较麻烦)
    int i;         // 第一个数组索引
    int j;         // 第二个数组索引
    int k;         // 临时数组索引

    for (i = l, j = m + 1, k = 0; k < len; k++)  // 分别将 i, j, k 指向各自数组的首部
    {
        // 若 i 到达第一个数组的尾部, 将第二个数组余下元素复制到临时数组中
        if (i == m + 1) {
            aux[k] = a[j++];
            continue;
        }
        // 若 j 到达第二个数组的尾部, 将第一个数组余下元素复制到临时数组中
        if (j == r + 1) {
            aux[k] = a[i++];
            continue;
        }
        // 如果第一个数组的当前元素 比 第二个数组的当前元素小, 将 第一个数组的当前元素 复制到临时数组中
        // 如果第二个数组的当前元素 比 第一个数组的当前元素小, 将 第二个数组的当前元素 复制到临时数组中
        if (a[i] < a[j]) {
            aux[k] = a[i++];
        } else {
            aux[k] = a[j++];
        }
    }

    // 将有序的临时数组元素 赋回 被排序的数组a中
    // i = left, 被排序的 数组a 的起始位置
    // j = 0, 临时数组的起始位置
    for (i = l, j = 0; i <= r; i++, j++) {
        a[i] = aux[j];
    }
}

// 归并排序[l, r]
void MergeSort(int a[], int l, int r)
{
    if (l < r) {
        int i;
        i = (l + r) / 2;
        MergeSort(a, l, i);
        MergeSort(a, i + 1, r);
        Merge(a, l, i, r);
    }
}

int main()
{
    const int N = 12;
    // 测试数据
    int arr_test[N] = {8, 4, 2, 3, 5, 1, 6, 9, 0, 7};
    // 排序前数组序列
    Show(arr_test, N);
    MergeSort(arr_test, 0, N - 1);
    // 排序后数组序列
    Show(arr_test, N);
    return 0;
}
