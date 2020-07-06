// #include <bits/stdc++.h>
#include <numeric>
#include <string>
#include <functional>
#include <iterator>
#include <iostream>     // std::cout
#include <sstream>      // std::istringstream
#include <algorithm>    // std::unique, std::distance, std::rotate,
                        // std::lower_bound, std::upper_bound, std::sort
                        // std::merge, std::min
#include <vector>       // std::vector
#include <queue>
#include <unordered_map>
#include <climits>
#include <cfloat>
#include <stack>        // std::stack

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    cout << '\n';
}
int main()
{
  /// std::accumulate
  {
    vector<int> v{1, 2, 3};

    int sum = std::accumulate(v.begin(), v.end(), 0);

    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

    auto dash_fold = [](string a, int b) {
                         return std::move(a) + '-' + std::to_string(b);
                     };

    string s = std::accumulate(std::next(v.begin()), v.end(),
                               std::to_string(v[0]), // start with first element
                               dash_fold);

    // Right fold using reverse iterators
    string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
                                std::to_string(v.back()), // start with last element
                                dash_fold);

    cout << "sum: " << sum << '\n'
         << "product: " << product << '\n'
         << "dash-separated string: " << s << '\n'
         << "dash-separated string (right-folded): " << rs << '\n';
  }

  /// std::partial_sum
  {
    vector<int> v = {2, 2, 2, 2, 2}; // or vector<int>v(5, 2);

    cout << "The first 5 偶数 are: ";
    std::partial_sum(v.begin(), v.end(),
                     std::ostream_iterator<int>(cout, " "));
    cout << '\n';

    std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
    cout << "The first 5 powers of 2 are: ";
    for (auto n : v) {
        cout << n << " ";
    }
    cout << '\n';

  }
  {
    string s = "231";
    std::sort(s.begin(), s.end());
    do {
        cout << s << '\n';
    } while(std::next_permutation(s.begin(), s.end()));
  }

  // lower_bound/upper_bound example
  {
    vector<int> v{1,2,3,3,2,2};
    std::sort(v.begin(), v.end());                      // 1 2 2 2 3 3
    auto low1= std::lower_bound(v.begin(), v.end(), 2); //   ^
    auto up1 = std::upper_bound(v.begin(), v.end(), 2); //         ^
    auto low2= std::lower_bound(v.begin(), v.end(), 4); //             ^
    auto up2 = std::upper_bound(v.begin(), v.end(), 4); //             ^
    // 合法的插入位置 0,1,...,n
    assert((low1 - v.begin())==1);
    assert((up1 - v.begin())==4);
    assert((low2 - v.begin())==6);
    assert((up2 - v.begin())==6);
  }

  // rotate algorithm example
  {
    vector<int> v{1, 2, 3, 4, 5};

    std::rotate(v.begin(),v.begin()+3,v.end()); // 4 5 1 2 3
    // print out content:
    cout << "rotate:";
    for (auto i:v)
      cout << ' ' << i;
    cout << '\n';
  }

  // STL_heap
  {
    using namespace std;
    //
    //堆的插入是在尾部，堆的删除是在顶部；
    //插入删除之后都需要重新调整堆。
    //这里使用的都是堆化数组，也就是用数组来存储堆；
    //

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

    int a[] = {0,1,1,1,3,3,1,1,0};           // 0 1 1 1 3 3 1 1 0
    vector<int> v (a,a+9);

    // using default comparison:
    vector<int>::iterator it;
    it = std::unique (v.begin(), v.end());   // 0 1 3 1 0 ? ? ? ?
                                             //           ^

    v.resize( std::distance(v.begin(),it) ); // 0 1 3 1 0

    // using predicate comparison:
    std::unique (v.begin(), v.end(), f);   // (no changes)

    // print out content:
    cout << "unique:";
    for (it=v.begin(); it!=v.end(); ++it)
      cout << ' ' << *it;
    cout << '\n';

  }
  {

    std::priority_queue<int> q;

    for(int n : {1,5,3,4,0,2})
        q.push(n);

    print_queue(q); // 5 4 3 2 1 0

    std::priority_queue<int, vector<int>, std::greater<int> > q2;

    for(int n : {1,5,3,4,0,2})
        q2.push(n);

    print_queue(q2); // 0 1 2 3 4 5

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, vector<int>, decltype(cmp)> q3(cmp);

    for(int n : {1,5,3,4,0,2})
        q3.push(n);

    print_queue(q3); // 4 5 2 3 0 1

  }

  { // merge algorithm example

    int first[] = {5,10,15,20,25};
    int second[] = {50,40,30,20,10};
    vector<int> v(10);

    std::sort (first,first+5);
    std::sort (second,second+5);
    std::merge (first,first+5,second,second+5,v.begin());

    cout << "The resulting vector contains:";
    for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
      cout << ' ' << *it;
    cout << '\n';

  }
  { // unordered_map::find

    std::unordered_map<string,double> m = {
       {"mom",5.4},
       {"dad",6.1} };

    m["bro"] = 5.9;
    assert(!m.empty());

    string str="mom";
    std::istringstream is(str);
    string input;
    getline (is,input); // cin

    std::unordered_map<string,double>::const_iterator got = m.find (input);

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
      cout << std::min({3, 1, 2, 4}) << endl;
      std::tuple<int, int> bounds = std::minmax({3, 1, 2, 4});
      cout << "min:" << std::get<0>(bounds) << endl;
      cout << "max:" << std::get<1>(bounds) << endl;
  }

  { // stack::push/pop

    std::stack<int> s;

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
