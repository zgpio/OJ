#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution
{
   public:
    string reverseWords(string s)
    {
        int i = 0;
        s.push_back(' ');
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == ' ') {
                // 反转s[i, j-1]
                int l = i, r = j - 1;
                while (l < r) {
                    swap(s[l], s[r]);
                    l++, r--;
                }
                i = j + 1;
            }
        }
        s.pop_back();
        return s;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.reverseWords("Let's take LeetCode contest") == "s'teL ekat edoCteeL tsetnoc");
    return 0;
}
