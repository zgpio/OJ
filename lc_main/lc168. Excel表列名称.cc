#include <iostream>
#include <string>
#include <vector>
using namespace std;
// ... 26^1 26^0
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
