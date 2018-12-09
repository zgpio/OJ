#include <assert.h>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> flag;
        int max = 0;
        int left = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto search = flag.find(s[i]);
            if (search != flag.end() && flag[s[i]] >= left) {
                if (i - left > max) max = i - left;
                left = flag[s[i]] + 1;
                flag[s[i]] = i;
            }
            else {
                flag[s[i]] = i;
            }
        }
        if (s.size() - left > max) max = s.size() - left;
        return max;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    assert(sol.lengthOfLongestSubstring("abcabcbb") == 3);
    assert(sol.lengthOfLongestSubstring("abcbbcbb") == 3);
    assert(sol.lengthOfLongestSubstring("abc") == 3);
    assert(sol.lengthOfLongestSubstring("bbbbbb") == 1);
    assert(sol.lengthOfLongestSubstring("aab") == 2);
    assert(sol.lengthOfLongestSubstring("abba") == 2);
    std::cout << "end" << std::endl;
    return 0;
}
