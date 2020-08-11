#include <bits/stdc++.h>
using namespace std;

// 队列一个元素
//    front  rear
//          
// ┌───┬───┬───┬───┐
// │   │ A │   │   │
// └───┴───┴───┴───┘
//
// 队列满
// rear front
//      
// ┌───┬───┬───┬───┐
// │   │ A │ B │ C │
// └───┴───┴───┴───┘
class MyCircularQueue {
public:
    // Initialize your data structure here. Set the size of the queue to be k.
    MyCircularQueue(int k) : head(0), tail(0), s(k + 1)
    {
        q = new int[k + 1];
    }
    ~MyCircularQueue()
    {
        delete[] q;
    }

    // Insert an element into the circular queue. Return true if the operation
    // is successful.
    bool enQueue(int value)
    {
        if (isFull())
            return false;
        else {
            q[tail++] = value;
            if (tail == s) tail = 0;
            return true;
        }
    }

    // Delete an element from the circular queue. Return true if the operation
    // is successful.
    bool deQueue()
    {
        if (isEmpty()) return false;
        head++;
        if (head == s) head = 0;
        return true;
    }

    // Get the front item from the queue.
    int Front()
    {
        if (isEmpty()) return -1;
        return q[head];
    }

    // Get the last item from the queue.
    int Rear()
    {
        if (isEmpty()) return -1;
        return q[(tail + s - 1) % s];
    }

    // Checks whether the circular queue is empty or not.
    bool isEmpty()
    {
        if (head == tail)
            return true;
        else
            return false;
    }

    // Checks whether the circular queue is full or not.
    bool isFull()
    {
        if ((tail + 1) % s == head)
            return true;
        else
            return false;
    }

private:
    int *q;
    int head, tail;
    int s;
};

int main(int argc, char *argv[])
{
    MyCircularQueue q(3);
    assert(q.enQueue(1) == true);
    assert(q.enQueue(2) == true);
    assert(q.enQueue(3) == true);
    assert(q.enQueue(4) == false);
    assert(q.Rear() == 3);
    assert(q.isFull() == true);
    assert(q.deQueue() == true);
    assert(q.enQueue(4) == true);
    assert(q.Rear() == 4);
    return 0;
}
