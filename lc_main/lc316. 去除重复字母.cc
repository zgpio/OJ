#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
   public:
    string removeDuplicateLetters(string s)
    {
        string v;
        // this lets us keep track of what's in our solution in O(1) time
        unordered_set<char> seen;

        // this will let us know if there are no more instances of s[i] left in s
        int last_occurrence[26];
        for (int i = 0; i < s.size(); i++) {
            last_occurrence[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            auto got = seen.find(s[i]);
            // we can only try to add c if it's not already in our solution
            // this is to maintain only one of each character
            if (got == seen.end()) {
                // if the last letter in our solution:
                //    1. exists
                //    2. is greater than c so removing it will make the string smaller
                //    3. it's not the last occurrence
                // we remove it from the solution to keep the solution optimal
                while (!v.empty() && s[i] < v.back() && i < last_occurrence[v.back() - 'a']) {
                    seen.erase(v.back());
                    v.pop_back();
                }
                seen.insert(s[i]);
                v.push_back(s[i]);
            }
        }
        return v;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    assert(s.removeDuplicateLetters("bcabc") == "abc");
    assert(s.removeDuplicateLetters("cbacdcbc") == "acdb");
    assert(s.removeDuplicateLetters("cbcdcbca") == "bcda");
    return 0;
}
