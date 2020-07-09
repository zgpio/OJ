#include <iostream>
#include <stack>
using namespace std;
template <typename QDataType>
class Queue {
public:
    void pop()
    {
        if (popable()) out.pop();
    }
    void push(QDataType e)
    {
        in.push(e);
        back_elem = e;
    }
    bool empty()
    {
        return (in.empty() && out.empty());
    }
    int size()
    {
        return in.size() + out.size();
    }
    QDataType front()
    {
        if (popable())
            return out.top();
        else {
            assert(0);
        }
    }
    QDataType back()
    {
        if (!empty()) {
            return back_elem;
        }
        else {
            assert(0);
        }
    }

private:
    bool popable()
    {
        if (empty()) return false;
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        return true;
    }

private:
    stack<QDataType> in;  // 入队栈
    stack<QDataType> out; // 出队栈
    QDataType back_elem;
};

int main(int argc, char *argv[])
{
    Queue<int> q;
    q.push(1);
    q.push(2);
    assert(q.front() == 1);
    assert(q.back() == 2);
    q.pop();
    assert(q.front() == 2);
    q.pop();
    assert(q.empty());

    {
        Queue<int> queue;
        //入队操作
        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.push(4);
        assert(queue.front() == 1);
        assert(queue.back() == 4);
        assert(queue.size() == 4);
        queue.pop();
        queue.pop();
        queue.pop();
        queue.pop();
        assert(queue.size() == 0);
    }

    return 0;
}
