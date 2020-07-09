#include "Queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// 1. 队列非空时(1个元素, 即尾指针指向的结点):
//    pHead        pTail
//                  
//  ┌───┬────┐   ┌───┬────┐
//  │ 0 │next│──▶│val│next│──▶NULL
//  └───┴────┘   └───┴────┘
//    头结点       尾结点
//
// 2. 队列为空时:
//  pHead/pTail
//      
//  ┌───┬────┐
//  │ 0 │next│──▶NULL
//  └───┴────┘
// 头结点/尾结点

// linkedQueue<QDataType>::pListNode 是私有的, 需要尾置
template<typename QDataType>
auto linkedQueue<QDataType>::BuyNode(QDataType d) -> linkedQueue<QDataType>::pListNode
{
    pListNode p = (pListNode)malloc(sizeof(ListNode));
    p->data = d;
    p->pNext = NULL;
    return p;
}

template<typename QDataType>
linkedQueue<QDataType>::linkedQueue()
{
    _pHead = BuyNode(0);
    _pTail = _pHead;
}

template<typename QDataType>
void linkedQueue<QDataType>::QueuePush(QDataType d)
{
    _pTail->pNext = BuyNode(d);
    _pTail = _pTail->pNext;
}

template<typename QDataType>
void linkedQueue<QDataType>::QueuePop()
{
    pListNode dNode = _pHead->pNext;
    if (dNode) {
        _pHead->pNext = dNode->pNext;
        if (_pHead->pNext == NULL) {
            _pTail = _pHead;
        } //如果只有一个元素, 删完后ptail会悬空
        free(dNode);
    }
}

template<typename QDataType>
int linkedQueue<QDataType>::QueueSize()
{
    pListNode pre = _pHead->pNext;
    int count = 0;
    while (pre) {
        count++;
        pre = pre->pNext;
    }
    return count;
}
template<typename QDataType>
bool linkedQueue<QDataType>::QueueEmpty()
{
    return NULL == _pHead->pNext;
}
template<typename QDataType>
QDataType linkedQueue<QDataType>::Front()
{
    return _pHead->pNext->data;
}
template<typename QDataType>
QDataType linkedQueue<QDataType>::Back()
{
    return _pTail->data;
}

int main(int argc, char *argv[])
{
    linkedQueue<int> q;
    assert(q.QueueEmpty()==true);
    assert(q.QueueSize()==0);
    q.QueuePush(1);
    assert(q.QueueSize()==1);
    assert(q.Back()==1);
    assert(q.Front()==1);
    q.QueuePop();
    assert(q.QueueSize()==0);
    return 0;
}
