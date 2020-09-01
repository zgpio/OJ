#include <bits/stdc++.h>

#define RADIX_10 10   // 整形排序
#define KEYNUM_31 10  // 关键字个数, 这里为整形位数

// 打印结果
void Show(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d  ", a[i]);
    printf("\n");
}

// 找到num的从低到高的第pos位(1-based)的数据
int GetNumInPos(int num, int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;

    return (num / temp) % 10;
}

// 基数排序无序数组a, n为无序数据个数
void RadixSort(int a[], int n)
{
    int *radixArrays[RADIX_10];  // 分别为0~9的序列空间
    for (int i = 0; i < RADIX_10; i++) {
        radixArrays[i] = (int *)malloc(sizeof(int) * (n + 1));
        radixArrays[i][0] = 0;  // index为0处记录这组数据的个数
    }

    for (int pos = 1; pos <= KEYNUM_31; pos++)  // 从个位开始到31位
    {
        for (int i = 0; i < n; i++)  // 分配过程
        {
            int num = GetNumInPos(a[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = a[i];
        }

        for (int i = 0, j = 0; i < RADIX_10; i++)  // 收集
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                a[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;  // 复位
        }
    }
    for (int i = 0; i < RADIX_10; i++) {
        free(radixArrays[i]);
    }
}

int main()
{
    assert(GetNumInPos(1234, 2) == 3);
    assert(GetNumInPos(12345678, 8) == 1);
    // 测试数据
    int a[] = {8, 4, 2, 3, 5, 1, 6, 9, 0, 7};
    int n = sizeof(a) / sizeof(int);
    // 排序前数组序列
    Show(a, n);
    RadixSort(a, n);
    // 排序后数组序列
    Show(a, n);
    return 0;
}
