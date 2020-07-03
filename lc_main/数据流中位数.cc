#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // fabs
#include <limits>
using namespace std;


class Solution
{
protected:
    vector<int>     m_min; //数组中的后一半元素组成一个最小化堆
    vector<int>     m_max; //数组中的前一半元素组成一个最大化堆

public:
    // 将元素插入的堆中,
    // 为了保证数据平均的分配到两个堆中, 两个堆的数据数目之差不能超过1.
    // 插入元素会破坏两个堆元素的平衡, 因此两个堆都必须调整
    //
    // 比如将元素插在后半段(最小堆)中,
    // 则最小堆调整后的堆顶(最小值)需要弹出并压入到前半段中才能保证平衡.
    // 也就是说, 在最小堆中插入元素, 最后完成调整后将导致最大堆中元素+1
    //
    // 保证 0 <= m_min.size() - m_max.size() <= 1
    // 那么
    //
    // 插入前如果整个数组的元素个数为偶数, 说明两个堆中元素个数相等
    // 则最终元素应该插入m_min中, 即先把元素插入到m_max中在调整到m_min中
    //
    // 插入前如果整个数组的元素个数为奇数, 说明m_max元素多了1个
    // 则最终元素应该插入m_max中, 即先把元素插入到m_min中在调整到m_max中
    void Insert(int num)
    {
        if(((m_min.size() + m_max.size()) & 1) == 0)
        {
            // 偶数数据的情况下
            // 1. 取出最大堆和新数据中的最大元素, 并调整最大堆;
            if(m_max.size() > 0 && num < m_max[0])
            {
                m_max.push_back(num);
                push_heap(m_max.begin(), m_max.end(), less<int>());

                num = m_max[0];
                pop_heap(m_max.begin(), m_max.end(), less<int>());
                m_max.pop_back();
            }
            // 2. 将最大元素插入最小堆中.
            m_min.push_back(num);
            push_heap(m_min.begin(), m_min.end(), greater<int>());
            // cout <<"left = " <<m_max.size() <<", " <<m_min.size() <<endl;
        }
        else
        {
            // 奇数数据的情况下
            // 1. 取出最小堆和新数据中的最小元素, 并调整最小堆;
            if(m_min.size() > 0 && num > m_min[0])
            {
                m_min.push_back(num);
                push_heap(m_min.begin(), m_min.end(), greater<int>());
                num=m_min[0];
                pop_heap(m_min.begin(), m_min.end(), greater<int>());
                m_min.pop_back();
            }
            // 2. 将最小元素插入最大堆中.
            m_max.push_back(num);
            push_heap(m_max.begin(), m_max.end(), less<int>());
        }
    }

    // 由于 0 <= m_min.size() - m_max.size() <= 1
    // 因此
    // 当总元素个数为偶数时, 中位数即(m_max[0] + m_min[0]) / 2
    // 当总元素个数为奇数时, 中位数即m_min[0];
    double GetMedian()
    {
        int size = m_min.size() + m_max.size();
        if(size==0) return -1;
        double median = 0;
        if((size & 1) != 0)
        {
            median = (double) m_min[0];
        }
        else
        {
            median = (double) (m_max[0] + m_min[0]) / 2;
        }
        return median;
    }
};

template <typename T>
bool essentiallyEqual(T a, T b, T epsilon)
{
    return fabs(a - b) <= ((fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon);
}
int main()
{
    Solution s;
    int array[] = {5, 2, 3, 4, 1, 6, 7, 0, 8};
    double res[] = {5, 3.5, 3, 3.5, 3, 3.5, 4, 3.5, 4};
    vector<int> vec(array, array + 9);

    for (int i = 0; i < vec.size(); i++)
    {
        s.Insert(vec[i]);
        assert(essentiallyEqual(s.GetMedian(), res[i], std::numeric_limits<double>::epsilon()));
        cout << s.GetMedian() << endl;
    }
    return 0;
}
