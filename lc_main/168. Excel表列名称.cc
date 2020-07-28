#include <iostream>
#include <string>
#include <vector>
using namespace std;
// ... 26^1 26^0
// 10进制0~9, 26进制0~25, 但是1~26分别对应A~Z, 存在偏移1
class Solution
{
   public:
    string convertToTitle(int n)
    {
        string ans;
        do
            ans = char('A' + (--n) % 26) + ans;
        while ((n /= 26) > 0);
        return ans;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.convertToTitle(1) == "A");
    assert(s.convertToTitle(28) == "AB");
    assert(s.convertToTitle(701) == "ZY");

    return 0;
}
