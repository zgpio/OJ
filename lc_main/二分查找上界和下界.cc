#include <iostream>
#include <vector>
#include <algorithm> // binary_search
using namespace std;

//返回target在有序向量A中出现的第一个位置
//如果target不在A中，则是target应该插入的位置
int lower_bound(vector<int> &A, int target)
{
    int l = 0, r = A.size();

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (target == A[mid]) {
            r = mid;
        }
        else if (target > A[mid]) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    return l;
}

//返回target在有序向量A中出现的第最后一个位置的下一个位置
//如果target不在A中，则是target应该插入的位置
int upper_bound(vector<int> &A, int target)
{
    int l = 0, r = A.size();

    while (l < r) {
        int mid = l + (r - l) / 2;
        if (target == A[mid]) {
            l = mid + 1;
        }
        else if (target > A[mid]) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }

    return r;
}

// lc704. 二分查找
int my_binary_search(vector<int> &A, int t)
{
    int l = 0, r = A.size();
    while (l < r) {
        int m = (l + r) / 2;
        if (A[m] == t)
            return m;
        else if (A[m] > t) {
            r = m;
        }
        else {
            l = m + 1;
        }
    }
    return -1;
}

// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR] 闭区间
int *generateRandomArray(int n, int rangeL, int rangeR)
{
    assert(rangeL <= rangeR);
    int *arr = new int[n]; // 创建一个 n个元素的数组
    srand(time(NULL));     // 随机种子
    for (int i = 0; i < n; i++)
        arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
    return arr;
}

int main()
{
    for (int i = 0; i < 100000; i++) {
        int len = 50;
        int l = -97, r = 101;
        int target = rand() % (r - l + 1) + l;
        int *a = generateRandomArray(len, l, r);
        vector<int> A(a, a + len);
        sort(A.begin(), A.end());
        if (binary_search(A.begin(), A.end(), target)==false)
        {
            assert(my_binary_search(A, target)==-1);
        }
        else
            assert(my_binary_search(A, target)>=0);
        int gt = lower_bound(A.begin(), A.end(), target) - A.begin();
        int pred = lower_bound(A, target);
        if (gt != pred) {
            printf("pred:%d, gt:%d, target:%d\n", pred, gt, target);
            for (int i = 0; i < A.size(); i++) {
                printf("%d:%d ", i, A[i]);
            }
            putchar('\n');
        }

        delete[] a;
    }

    return 0;
}
