#include "Queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

linkedQueue::pListNode linkedQueue::BuyNode(QDataType d)
{
    pListNode p = (pListNode)malloc(sizeof(ListNode));
    p->_data = d;
    p->_pNext = NULL;
    return p;
}

linkedQueue::linkedQueue()
{
    _pHead = BuyNode(0);
    _pTail = _pHead;
}

void linkedQueue::QueuePush(QDataType d)
{
    _pTail->_pNext = BuyNode(d);
    _pTail = _pTail->_pNext;
}

void linkedQueue::QueuePop()
{
    pListNode dNode = _pHead->_pNext;
    if (dNode) {
        _pHead->_pNext = dNode->_pNext;
        if (_pHead->_pNext == NULL) {
            _pTail = _pHead;
        } //如果只有一个元素，删完后ptail会悬空
        free(dNode);
    }
}

int linkedQueue::QueueSize()
{
    pListNode pre = _pHead->_pNext;
    int count = 0;
    while (pre) {
        count++;
        pre = pre->_pNext;
    }
    return count;
}
bool linkedQueue::QueueEmpty()
{
    return NULL == _pHead->_pNext;
}
linkedQueue::QDataType linkedQueue::Front()
{
    return _pHead->_pNext->_data;
}
linkedQueue::QDataType linkedQueue::Back()
{
    return _pTail->_data;
}

int main(int argc, char *argv[])
{
    linkedQueue q;
    assert(q.QueueEmpty()==true);
    assert(q.QueueSize()==0);
    q.QueuePush(1);
    assert(q.QueueSize()==1);
    q.QueuePop();
    assert(q.QueueSize()==0);
    return 0;
}
