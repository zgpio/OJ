#include <numeric>
#include <string>
#include <functional>
#include <iterator>
#include <iostream>     // std::cout
#include <algorithm>    // std::unique, std::distance, std::rotate,
                        // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector
#include <queue>

using std::cout;
template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}
int main()
{
  /// std::accumulate
  {
    std::vector<int> v{1, 2, 3, 4};

    int sum = std::accumulate(v.begin(), v.end(), 0);

    int product = std::accumulate(v.begin(), v.end(), 1, std::multiplies<int>());

    auto dash_fold = [](std::string a, int b) {
                         return std::move(a) + '-' + std::to_string(b);
                     };

    std::string s = std::accumulate(std::next(v.begin()), v.end(),
                                    std::to_string(v[0]), // start with first element
                                    dash_fold);

    // Right fold using reverse iterators
    std::string rs = std::accumulate(std::next(v.rbegin()), v.rend(),
                                     std::to_string(v.back()), // start with last element
                                     dash_fold);

    cout << "sum: " << sum << '\n'
         << "product: " << product << '\n'
         << "dash-separated string: " << s << '\n'
         << "dash-separated string (right-folded): " << rs << '\n';
  }

  /// std::partial_sum
  {
    std::vector<int> v = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2}; // or std::vector<int>v(10, 2);

    cout << "The first 10 偶数 are: ";
    std::partial_sum(v.begin(), v.end(),
                     std::ostream_iterator<int>(cout, " "));
    cout << '\n';

    std::partial_sum(v.begin(), v.end(), v.begin(), std::multiplies<int>());
    cout << "The first 10 powers of 2 are: ";
    for (auto n : v) {
        cout << n << " ";
    }
    cout << '\n';

  }
  {
    std::string s = "231";
    std::sort(s.begin(), s.end());
    do {
        cout << s << '\n';
    } while(std::next_permutation(s.begin(), s.end()));
  }

  // lower_bound/upper_bound example
  {
    int myints[] = {10,20,30,30,20,10,10,20};
    std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
    std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30
    std::vector<int>::iterator low,up;
    low=std::lower_bound (v.begin(), v.end(), 20); //          ^
    up= std::upper_bound (v.begin(), v.end(), 20); //                   ^

    std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
  }

  // rotate algorithm example
  {
    std::vector<int> myvector;

    // set some values:
    for (int i=1; i<10; ++i) myvector.push_back(i); // 1 2 3 4 5 6 7 8 9

    std::rotate(myvector.begin(),myvector.begin()+3,myvector.end());
                                                    // 4 5 6 7 8 9 1 2 3
    // print out content:
    cout << "myvector contains:";
    for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
      cout << ' ' << *it;
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

    int arr[] = {4,5,6,7,8,1};
    vector<int>vectorArr(arr,arr + sizeof(arr) / sizeof(int));

    cout <<"1) "<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    // 构造最大堆
    make_heap(vectorArr.begin(), vectorArr.end(), less<int>());
    cout <<"2) "<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    // 向堆中插入一个元素，默认插入在顶部
    vectorArr.push_back(100);
    cout <<"3) "<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;
    push_heap(vectorArr.begin(), vectorArr.end());
    cout <<"4) "<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    // 弹出一个元素，默认是首元素和尾元素交换，交换以后就不是正确的堆了；真正的删除需要去vector里面pop；
    pop_heap(vectorArr.begin(), vectorArr.end());
    cout <<"5) "<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;
    vectorArr.pop_back();
    cout <<"6) "<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;

    // 堆排序, 堆排序后
    sort_heap(vectorArr.begin(), vectorArr.end());
    cout <<"7) "<<is_heap(vectorArr.begin(), vectorArr.end()) << endl;
    for (int i = 0; i < vectorArr.size(); i++)
    {
        cout << vectorArr[i] << " ";
    }
    cout << endl;

  }
  // unique algorithm example
  {

    auto f = [](int i, int j) -> bool {
      return (i==j);
    };

    int myints[] = {10,20,20,20,30,30,20,20,10};           // 10 20 20 20 30 30 20 20 10
    std::vector<int> myvector (myints,myints+9);

    // using default comparison:
    std::vector<int>::iterator it;
    it = std::unique (myvector.begin(), myvector.end());   // 10 20 30 20 10 ?  ?  ?  ?
                                                           //                ^

    myvector.resize( std::distance(myvector.begin(),it) ); // 10 20 30 20 10

    // using predicate comparison:
    std::unique (myvector.begin(), myvector.end(), f);   // (no changes)

    // print out content:
    std::cout << "myvector contains:";
    for (it=myvector.begin(); it!=myvector.end(); ++it)
      std::cout << ' ' << *it;
    std::cout << '\n';

  }
  {

    std::priority_queue<int> q;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);

    print_queue(q);

    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);

    print_queue(q2);

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);

    print_queue(q3);

  }
}
