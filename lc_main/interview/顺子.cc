#include <bits/stdc++.h>
using namespace std;

#define BIT_GET(value, bit) (((value) >> (bit)) & 0x01)
#define BIT_SET(value, bit) ((value) |= (1UL << (bit)))
#define BIT_CLR(value, bit) ((value) &= ~(1UL << (bit)))
#define BIT_CPL(value, bit) ((value) ^= (1UL << (bit))) // 取反

class Solution {
public:
  bool IsContinuous(vector<int> numbers) {
    if (numbers.size() != 5) {
      return false;
    }
    int min = INT_MAX;
    int max = INT_MIN;
    int flag = 0;

    for (int i = 0; i < numbers.size(); i++) {
      int num = numbers[i];

      if (num < 0 || num > 13) // 牌只能在0~13之间
      {
        return false;
      } else if (num == 0) // 0用来答题任何牌，因此不能参与最大最小牌的比对
      {
        continue;
      }

      // 非0元素不能重复
      if (BIT_GET(flag, num) == 1) // 如果flag的第num位为1, 说明num重复
      {
        cout << i << ", " << num << endl;
        return false;
      } else {
        BIT_SET(flag, num); // 将标识flag的第num位置为0
      }
      // 寻找最大最小的牌
      if (num > max) {
        max = num;
      }
      if (num < min) {
        min = num;
      }
      cout << "max = " << max << ", min = " << min << endl;

      // 如果最大值和最小值的差值大于4, 那么必应不能补齐
      if (max - min > 4) {
        cout << "max = " << max << ", min = " << min << endl;
        return false;
      }
    }
    return true;
  }
};
int main(int argc, char *argv[]) {
  Solution s;
  assert(s.IsContinuous({1, 2, 3, 4, 5}) == true);
  return 0;
}
