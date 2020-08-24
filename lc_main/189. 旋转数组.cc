#include <iostream>
#include <vector>
using namespace std;

class Solution1
{
   public:
    void rotate(vector<int>& nums, int k)
    {
        const int n = nums.size();
        k = k % n;
        int cnt = 0;
        for (int start = 0; cnt < n; start++) {
            int current = start;
            int prev = nums[start];
            do {
                int next = (current + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                current = next;
                cnt++;
            } while (start != current);
        }
    }
};

class Solution2
{
   public:
    void rotate(vector<int>& nums, int k)
    {
        const int n = nums.size();
        k %= n;
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }

   private:
    void reverse(vector<int>& nums, int start, int end)
    {
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
};

int main(int argc, char* argv[])
{
    Solution1 s1;
    Solution1 s2;
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;
        s1.rotate(v, k);
        assert(v == (vector<int>{5, 6, 7, 1, 2, 3, 4}));
    }
    {
        vector<int> v = {1, 2, 3, 4, 5, 6, 7};
        int k = 3;
        s2.rotate(v, k);
        assert(v == (vector<int>{5, 6, 7, 1, 2, 3, 4}));
    }
    return 0;
}
