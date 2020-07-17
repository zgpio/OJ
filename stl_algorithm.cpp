// #include <bits/stdc++.h>
#include <numeric>
#include <string>       // to_string
#include <functional>   // greater, less
#include <iterator>     // next
#include <iostream>     // cin, cout, cerr, endl
#include <sstream>      // istringstream
#include <algorithm>    // unique, distance, rotate, lower_bound, upper_bound, sort, merge, min
#include <vector>       // vector
#include <tuple>        // tuple
#include <queue>
#include <unordered_map>
#include <climits>
#include <cfloat>
#include <stack>        // stack

using std::vector;
using std::string;
using namespace std;
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << '\n';
}
int main()
{
  /// accumulate
  {
    vector<int> v{1, 2, 3};

    int sum = accumulate(v.begin(), v.end(), 0);

    int product = accumulate(v.begin(), v.end(), 1, multiplies<int>());

    auto dash_fold = [](string a, int b) {
                         return move(a) + '-' + to_string(b);
                     };

    string s = accumulate(next(v.begin()), v.end(),
                          to_string(v[0]), // start with first element
                          dash_fold);

    // Right fold using reverse iterators
    string rs = accumulate(next(v.rbegin()), v.rend(),
                           to_string(v.back()), // start with last element
                           dash_fold);

    cout << "累加: " << sum << '\n'
         << "累积: " << product << '\n'
         << "dash-separated string: " << s << '\n'
         << "dash-separated string (right-folded): " << rs << '\n';
  }

  /// partial_sum
  {
    vector<int> v = {2, 2, 2, 2, 2}; // or vector<int>v(5, 2);

    cout << "前5个偶数: ";
    partial_sum(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    cout << '\n';

    partial_sum(v.begin(), v.end(), v.begin(), multiplies<int>());
    cout << "前5个2的幂: ";
    for (auto n : v) {
        cout << n << " ";
    }
    cout << '\n';

  }
  {
    string s = "231";
    sort(s.begin(), s.end());
    do {
        cout << s << '\n';
    } while(next_permutation(s.begin(), s.end()));
  }

  // lower_bound/upper_bound
  {
    vector<int> v{1,2,3,3,2,2};
    sort(v.begin(), v.end());                      // 1 2 2 2 3 3
    auto low1= lower_bound(v.begin(), v.end(), 2); //   ^
    auto up1 = upper_bound(v.begin(), v.end(), 2); //         ^
    auto low2= lower_bound(v.begin(), v.end(), 4); //             ^
    auto up2 = upper_bound(v.begin(), v.end(), 4); //             ^
    // 合法的插入位置 0,1,...,n
    assert(binary_search(v.begin(), v.end(), 2)==true);
    assert(binary_search(v.begin(), v.end(), 4)==false);
    assert((low1 - v.begin())==1);
    assert((up1 - v.begin())==4);
    assert((low2 - v.begin())==6);
    assert((up2 - v.begin())==6);
  }

  // rotate algorithm example
  {
    vector<int> v{1, 2, 3, 4, 5};

    rotate(v.begin(), v.begin()+3, v.end()); // 4 5 1 2 3

    cout << "rotate:";
    for (auto i:v)
      cout << ' ' << i;
    cout << '\n';
  }

  // STL_heap
  {
    //堆的插入是在尾部，堆的删除是在顶部；
    //插入删除之后都需要重新调整堆。
    //这里使用的都是堆化数组，也就是用数组来存储堆；

    int a[] = {4,5,6,7,8,1};
    vector<int> v(a, a + sizeof(a) / sizeof(int));

    assert(!is_heap(v.begin(), v.end()));

    // 构造最大堆
    make_heap(v.begin(), v.end(), less<int>()); // greater<int>()
    assert(is_heap(v.begin(), v.end()));

    // 向堆中插入一个元素，默认插入在顶部
    v.push_back(100);
    assert(!is_heap(v.begin(), v.end()));
    push_heap(v.begin(), v.end());
    assert(is_heap(v.begin(), v.end()));

    // 弹出一个元素，默认是首元素和尾元素交换，交换以后就不是正确的堆了；真正的删除需要去vector里面pop；
    pop_heap(v.begin(), v.end());
    assert(!is_heap(v.begin(), v.end()));
    v.pop_back();
    assert(is_heap(v.begin(), v.end()));

    // 堆排序: 最大堆 -> 升序序列
    sort_heap(v.begin(), v.end());
    assert(!is_heap(v.begin(), v.end()));
    cout << "STL_heap: ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

  }
  // unique algorithm example
  {

    auto f = [](int i, int j) -> bool {
      return (i==j);
    };

    int a[] = {0,1,1,1,3,3,1,1,0};     // 0 1 1 1 3 3 1 1 0
    vector<int> v (a,a+9);

    // using default comparison:
    vector<int>::iterator it;
    it = unique(v.begin(), v.end());   // 0 1 3 1 0 ? ? ? ?
                                       //           ^

    v.resize(distance(v.begin(),it));  // 0 1 3 1 0

    // using predicate comparison:
    unique(v.begin(), v.end(), f);     // (no changes)

    cout << "unique:";
    for (it=v.begin(); it!=v.end(); ++it)
      cout << ' ' << *it;
    cout << '\n';

  }
  {

    priority_queue<int> q;

    for(int n : {1,5,3,4,0,2})
        q.push(n);

    print_queue(q); // 5 4 3 2 1 0

    priority_queue<int, vector<int>, greater<int> > q2;

    for(int n : {1,5,3,4,0,2})
        q2.push(n);

    print_queue(q2); // 0 1 2 3 4 5

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);

    for(int n : {1,5,3,4,0,2})
        q3.push(n);

    print_queue(q3); // 4 5 2 3 0 1

  }

  { // merge algorithm example

    int first[] = {5,10,15,20,25};
    int second[] = {50,40,30,20,10};
    vector<int> v(10);

    sort(first, first+5);
    sort(second, second+5);
    merge(first, first+5, second, second+5, v.begin());

    cout << "合并两个有序数组:";
    for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
      cout << ' ' << *it;
    cout << '\n';

  }
  { // unordered_map::find

    unordered_map<string,double> m = {
       {"mom",5.4},
       {"dad",6.1} };

    m["bro"] = 5.9;
    assert(!m.empty());

    string str="mom";
    istringstream is(str);
    string input;
    getline (is,input); // cin

    unordered_map<string,double>::const_iterator got = m.find (input);

    if ( got == m.end() )
      cout << "not found:" << input;
    else
      cout << got->first << " is " << got->second;

    cout << endl;

  }
  { // <climits> <cfloat>
      INT_MAX;
      INT_MIN;
      UINT_MAX;
      SHRT_MAX;
      LONG_MAX;
      cout << min({3, 1, 2, 4}) << endl;
      tuple<int, int> bounds = minmax({3, 1, 2, 4});
      cout << "min:" << get<0>(bounds) << endl;
      cout << "max:" << get<1>(bounds) << endl;
  }

  { // stack::push/pop

    stack<int> s;

    for (int i=0; i<5; ++i) s.push(i);

    cout << "Popping out elements...";
    while (!s.empty())
    {
       cout << ' ' << s.top();
       s.pop();
    }
    cout << endl;

  }
}
