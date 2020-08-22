#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  Solution() {
    str = "";
    memset(count, '\0', sizeof(count));
  }

  // Insert one char from stringstream
  void Insert(char ch) {
    str += ch;
    count[(int)ch]++;
  }

  // Return the first appearence once char in current stringstream
  char FirstAppearingOnce() {
    int len = str.size();
    for (int i = 0; i < len; i++) {
      if (count[(int)str[i]] == 1) {
        return str[i];
      }
    }
    return '#';
  }

private:
  std::string str;
  int count[256];
};

int main() {

  Solution s;

  s.Insert('g');
  cout << s.FirstAppearingOnce() << endl;

  s.Insert('o');
  cout << s.FirstAppearingOnce() << endl;

  s.Insert('o');
  cout << s.FirstAppearingOnce() << endl;

  s.Insert('g');
  cout << s.FirstAppearingOnce() << endl;

  s.Insert('l');
  cout << s.FirstAppearingOnce() << endl;

  s.Insert('e');
  cout << s.FirstAppearingOnce() << endl;

  return 0;
}
