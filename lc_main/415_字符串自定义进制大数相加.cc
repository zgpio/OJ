#include <bits/stdc++.h>
using namespace std;

// TODO 自定义进制相加
string addStrings(string a, string b)
{
    if (a.size() < b.size()) {
        swap(a, b);
    }
    // 确保a长于b
    int i = a.size() - 1;  // auto 会推断成size_type, 无符号类型>=0恒成立, 造成死循环
    int j = b.size() - 1;
    int flag = 0;
    for (; j >= 0; j--, i--) {
        int sum = (a[i] - '0') + (b[j] - '0') + flag;
        if (sum >= 10) {
            flag = 1;
            sum -= 10;
        } else
            flag = 0;
        a[i] = sum + '0';
    }
    while (i >= 0) {
        int sum = (a[i] - '0') + flag;
        if (sum >= 10) {
            flag = 1;
            sum -= 10;
        } else
            flag = 0;
        a[i] = sum + '0';
        i--;
    }
    if (flag)
        a.insert(a.begin(), '1');
    return a;
}
string subStrings(string a, string b)
{
    if (a == b)
        return "0";
    if (a.size() < b.size()) {
        swap(a, b);
    }
    // a - b 确保a大于b
    int flag = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;
    for (; j >= 0; i--, j--) {
        int sub = (a[i] - '0') - (b[j] - '0') - flag;
        if (sub < 0) {
            flag = 1;
            sub += 10;
        } else
            flag = 0;
        a[i] = sub + '0';
    }
    for (; i >= 0; i--) {
        int sub = (a[i] - '0') - flag;
        if (sub < 0) {
            flag = 1;
            sub += 10;
        } else
            flag = 0;
        a[i] = sub + '0';
    }
    a.erase(0, a.find_first_not_of("0"));
    return a;
}

int main(int argc, char *argv[])
{
    {
        vector<tuple<string, string, string>> cases
            = {{"1234", "1245", "2479"}, {"1", "9", "10"}, {"1111236", "1245", "1112481"}, {"19236", "1245", "20481"}};
        for (auto i : cases) {
            assert(addStrings(get<0>(i), get<1>(i)) == get<2>(i));
        }
    }
    {
        vector<tuple<string, string, string>> cases
            = {{"1255", "1245", "10"}, {"99", "9", "90"}, {"1236", "0", "1236"}, {"11", "11", "0"}, {"100", "99", "1"}};
        for (auto i : cases) {
            assert(subStrings(get<0>(i), get<1>(i)) == get<2>(i));
        }
    }
    return 0;
}
