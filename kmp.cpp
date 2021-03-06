#include <cassert>
#include <cstring>
#include <iostream>

using std::cout;
using std::endl;

int *make_pmt(const char *p) // O(m)
{
    size_t len = strlen(p);
    int *ret = static_cast<int *>(malloc(sizeof(int) * len));
    assert(ret != nullptr);

    int ll = 0; // 原模式串的子串对应的前缀后缀的公共元素的最大长度

    // 第0个元素的ll值为0
    ret[0] = 0;

    for (size_t i = 1; i < len; ++i) {
        // 假设不成功时，再次尝试扩展
        while ((ll > 0) && (p[i] != p[ll])) {
            ll = ret[ll - 1];
        }

        // 对首尾字符或者扩展后的字符进行判断
        if (p[i] == p[ll]) {
            ++ll;
        }

        ret[i] = ll;
    }

    return ret;
}

int kmp(const char *s, const char *p) // O(m + n)
{
    int ret = -1;
    int sl = strlen(s);
    int pl = strlen(p);
    if (sl == 0 || pl == 0) return -1;
    int *pmt = make_pmt(p); // O(m)

    if ((0 < pl) && (pl <= sl)) {
        for (int i = 0, j = 0; i < sl; ++i) // O(n)
        {
            while ((j > 0) && (s[i] != p[j])) {
                j = pmt[j - 1]; // j = j - (j - LL) = LL = PMT[j-1];
            }

            if (s[i] == p[j]) {
                ++j;
            }

            if (j == pl) {
                ret = i + 1 - pl;
                break;
            }
        }
    }

    free(pmt);

    return ret;
}

int main()
{
    assert(kmp("abcde", "cde") == 2);
    assert(kmp("abcdecde", "cde") == 2);
    assert(kmp("abcde", "") == -1);
    assert(kmp("abcde", "a") == 0);
    assert(kmp("abcde", "bc") == 1);
    assert(kmp("BBC ABCDAB ABCDABCDABDE", "ABCDABD") == 15);
    // http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html
    //   │B│B│C│ │A│B│C│D│A│B│ │A│B│C│D│A│B│C│D│A│B│D│E│
    // 1 │A│B│C│D│A│B│D│ │ │ │ │ │ │ │ │ │ │ │ │ │ │ │ │
    // 2 │ │A│B│C│D│A│B│D│ │ │ │ │ │ │ │ │ │ │ │ │ │ │ │
    // 3 │ │ │A│B│C│D│A│B│D│ │ │ │ │ │ │ │ │ │ │ │ │ │ │
    // 4 │ │ │ │A│B│C│D│A│B│D│ │ │ │ │ │ │ │ │ │ │ │ │ │
    // 5 │ │ │ │ │A│B│C│D│A│B│D│ │ │ │ │ │ │ │ │ │ │ │ │
    // 6 │ │ │ │ │ │ │ │ │A│B│C│D│A│B│D│ │ │ │ │ │ │ │ │
    // 7 │ │ │ │ │ │ │ │ │ │ │A│B│C│D│A│B│D│ │ │ │ │ │ │
    // 8 │ │ │ │ │ │ │ │ │ │ │ │A│B│C│D│A│B│D│ │ │ │ │ │
    // 9 │ │ │ │ │ │ │ │ │ │ │ │ │ │ │ │A│B│C│D│A│B│D│ │
    //
    // 部分匹配表(Partial Match Table), "部分匹配值"就是"前缀"和"后缀"的最长的共有元素的长度.
    // │A│B│C│D│A│B│D│
    // │0│0│0│0│1│2│0│

    return 0;
}
