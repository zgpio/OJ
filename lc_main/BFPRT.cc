#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
// https://ethsonliu.com/2018/03/bfprt.html
#define N 15
void InsertSort(int array[], int left, int right);
int FindMid(int array[], int left, int right);
int FindPosition(int array[], int left, int right, int num);
int Partion(int array[], int left, int right, int privot);
int BFPRT(int array[], int left, int right, int k);

int main()
{
    int k = 4;
    int array[N] = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 11, 13, 15, 12, 14};
    for (int i = 0; i < N; i++)
        printf("%d ", array[i]);
    printf("\n");
    printf("第 %d 大值： %d \n", k, BFPRT(array, 0, N - 1, k));
    for (int i = 0; i < N; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

void InsertSort(int a[], int left, int right)
{
    int j, k;
    for (int i = left; i < right; i++) {
        if (a[i] > a[i + 1]) {
            k = a[i + 1];
            j = i + 1;
            while (j > left && a[j - 1] > k) {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = k;
        }
    }
}

// 找序列的中位数
int FindMid(int a[], int left, int right)
{
    if (left == right) return a[right];
    int i = 0;
    int j = 0;
    for (i = left; i < right - 5; i += 5) {
        InsertSort(a, i, i + 4);
        j = i - left;
        swap(a[left + j / 5], a[i + 2]);
    }
    int num = right - i + 1;
    if (num > 0) {
        InsertSort(a, i, i + num - 1);
        j = i - left;
        swap(a[left + j / 5], a[i + num / 2]);
    }
    j /= 5;
    if (j == left) return a[left];
    return FindMid(a, left, left + j);
}

int FindPosition(int a[], int left, int right, int num)
{
    for (int i = left; i <= right; i++)
        if (a[i] == num) return i;
    return -1;
}

int Partion(int a[], int left, int right, int privot)
{
    swap(a[privot], a[left]);
    int i = left;
    int j = right;
    int pivot = a[left];
    while (i < j) {
        while (a[j] <= pivot && i < j)
            j--;
        a[i] = a[j];
        while (a[i] >= pivot && i < j)
            i++;
        a[j] = a[i];
    }
    a[i] = pivot;
    return i;
}

int BFPRT(int a[], int left, int right, int k)
{
    int mid = FindMid(a, left, right);
    int privot = FindPosition(a, left, right, mid);
    int pos = Partion(a, left, right, privot);
    int num = pos - left + 1;
    if (num == k) return a[pos];
    if (num > k) return BFPRT(a, left, pos - 1, k);
    return BFPRT(a, pos + 1, right, k - num);
}
