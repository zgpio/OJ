#ifndef Queue_h
#define Queue_h

template<typename QDataType>
class linkedQueue {
public:
    linkedQueue();
    void QueuePush(QDataType d);  //进队列（尾插）
    void QueuePop();              //出队列（头删）
    int QueueSize();              //求队列大小
    bool QueueEmpty();             //队列判空
    QDataType Front();            //获取队头元素
    QDataType Back();             //获取队尾元素
private:
    typedef struct ListNode //通过链表实现的
    {
        QDataType data;
        struct ListNode *pNext;
    } ListNode, *pListNode;
    pListNode _pHead; //头指针
    pListNode _pTail; //尾指针
    pListNode BuyNode(QDataType d);
};

#endif /* Queue_h */
