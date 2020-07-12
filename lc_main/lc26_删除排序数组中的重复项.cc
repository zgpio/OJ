#include <algorithm>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() == 0) return 0;
    int i = 0;
    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }
    // nums.resize(i + 1);
    return i + 1;
}

int main(int argc, char *argv[])
{
    vector<int> a{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    assert(removeDuplicates(a) == 5);
    return 0;
}
