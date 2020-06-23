#include "lc/lc.h"
using namespace std;

class LRUCache {
private:
    // LRU数据结构
    struct Node {
        int key;
        int value;
        Node(int k, int v) : key(k), value(v)
        {
        }
    };

public:
    LRUCache(int c) : capacity(c)
    {
    }

    int get(int key)
    {
        if (cacheMap.find(key) == cacheMap.end())
            return -1; //这里产生缺页中断, 根据页表将页面调入内存, 然后set(key, value)
        //将key移到第一个, 并更新cacheMap
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        cacheMap[key] = cacheList.begin();
        return cacheMap[key]->value;
    }
    void set(int key, int value)
    {
        if (cacheMap.find(key) == cacheMap.end()) {
            //淘汰最后一个, 然后将其加到第一个位置
            if (cacheList.size() == capacity) {
                cacheMap.erase(cacheList.back().key);
                cacheList.pop_back();
            }
            cacheList.push_front(Node(key, value));
            cacheMap[key] = cacheList.begin();
        }
        else {
            //更新节点的值, 并将其加到第一个位置
            cacheMap[key]->value = value;
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key] = cacheList.begin();
        }
    }

private:
    int capacity;
    list<Node> cacheList;
    unordered_map<int, list<Node>::iterator> cacheMap;
};

int main(int argc, char *argv[])
{
    auto a = LRUCache(100);
    // initialize random seed:
    srand (time(NULL));

    int setkey_cnt = 0;
    for (int i=0;i<100;i++) {
        // generate secret number between 1 and 100:
        int key = rand() % 100 + 1;
        int v = a.get(key);
        if (v==-1) {
            a.set(key, 1);
            setkey_cnt++;
        }
    }
    printf("set key %d times\n", setkey_cnt);

    return 0;
}
