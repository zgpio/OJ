#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void replaceSpace(char *str, int length)
    {
        int cnt = 0; // 统计空格数
        for (int i = 0; i < length; i++) {
            if (str[i] == ' ') {
                cnt++;
            }
        }

        int len = length + cnt * 2;
        for (int i = length - 1, j = len - 1; i >= 0 && j >= 0;) {
            if (str[i] == ' ') {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            }
            else {
                str[j--] = str[i--];
            }
        }
        str[len] = '\0';
    }
};

int main()
{
    char str[4 + 3 * 3 + 1] = "a b c d";

    Solution solu;
    solu.replaceSpace(str, strlen(str));

    cout << str << endl;

    return 0;
}
