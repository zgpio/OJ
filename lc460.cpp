#include <assert.h>
#include <cstdio>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <string>
#include <tuple>
#include <unordered_map>
using namespace std;
//#include <hash_map>
// using namespace __gnu_cxx;

typedef struct {
    int v, fre;
    deque<int>::iterator pos;
} node;
// struct node {
//     int k, cnt;
//     bool operator<(const node& a) const { return cnt > a.cnt; }
// } k;
// priority_queue<node> q;

class LFUCache {
    int len;
    int min_fre;
    unordered_map<int, node> kv;
    unordered_map<int, deque<int>> fre;

public:
    LFUCache(int capacity) : len(capacity), min_fre(0) {}
    int get(int key)
    {
        auto ptr = kv.find(key);
        if (ptr != kv.end()) {
            int ofre = ptr->second.fre;
            fre[ofre].erase(ptr->second.pos);
            if (fre[ofre].empty()) {
                fre.erase(ofre);
                if (ofre == min_fre) min_fre++;
            }
            auto p = fre.find(ofre + 1);
            if (p != fre.end())
                p->second.push_back(key);
            else
                fre[ofre + 1] = deque<int>(key);  // insert a new
            ptr->second.fre++;
            ptr->second.pos = fre[ofre + 1].end() - 1;

            // char info[10];
            // sprintf(info, "get(%d):", key);
            // print(info);
            return ptr->second.v;
        }
        return -1;
    }

    void put(int key, int value)
    {
        auto ptr = kv.find(key);
        if (ptr != kv.end()) {
            ptr->second.v = value;
            get(key);
            return;
        }
        if (kv.size() >= len) {
            int dlkey = fre[min_fre].front();
            fre[min_fre].pop_front();
            if (fre[min_fre].empty()) fre.erase(min_fre);
            kv.erase(dlkey);
        }
        node nd;
        nd.v = value;
        nd.fre = 0;
        auto p = fre.find(0);
        if (p != fre.end())
            p->second.push_back(key);
        else
            fre[0] = deque<int>(key);
        nd.pos = fre[0].end() - 1;
        kv[key] = nd;
        min_fre = 0;

        // char info[10];
        // sprintf(info, "put(%d, %d):", key, value);
        // print(info);
    }
    void print(string info)
    {
        return;
        cout << info << endl;
        for (unordered_map<int, node>::iterator Iter = kv.begin();
             Iter != kv.end(); ++Iter) {
            cout << Iter->first << " " << Iter->second.v << " "
                 << Iter->second.fre << endl;
        }
        for (unordered_map<int, deque<int>>::iterator Iter = fre.begin();
             Iter != fre.end(); ++Iter) {
            cout << Iter->first << ":" << endl << "  ";
            for (deque<int>::iterator x = Iter->second.begin();
                 x != Iter->second.end(); ++x) {
                cout << " " << *x << " ";
            }
            std::cout << std::endl;
        }
        cout << endl;
    }
};

// clang --target=x86_64-pc-mingw32 lc460.cpp
int main()
{
    // tuple<int, int> a = make_tuple(2, 3);
    // std::cout << get<0>(a) << std::endl;
    // std::cout << get<1>(a) << std::endl;
    // int param_1 = obj.get(3);

    // LFUCache obj = *new LFUCache(3);
    // obj.put(1, 1);
    // obj.put(2, 2);
    // assert(obj.get(1) == 1);   // returns 1
    // obj.put(3, 3);             // evicts key 2
    // assert(obj.get(2) == 2);  // returns -1 (not found)
    // assert(obj.get(3) == 3);   // returns 3.
    // obj.put(4, 4);             // evicts key 1.
    // assert(obj.get(1) == -1);  // returns -1 (not found)
    // assert(obj.get(3) == 3);   // returns 3
    // assert(obj.get(4) == 4);   // returns 4

    LFUCache obj = *new LFUCache(512);
    ifstream in("./input/lc460");
    // LFUCache obj = *new LFUCache(105);
    // ifstream in("./input/lc460_2");
    string filename;
    string line;

    int cnt = 1;
    if (in) {
        while (getline(in, line))  // line中不包括每行的换行符
        {
            cout << cnt++ << ": ";
            // cout << line << endl;
            int idx = line.find(",");
            int a, b;

            const char *p = line.c_str();  // const不能省去！
            if (idx < line.length())       // find it
            {
                sscanf(p, "%d,%d", &a, &b);
                obj.put(a, b);
            }
            else {
                sscanf(p, "%d", &a);
                cout << obj.get(a);
            }
            std::cout << std::endl;
        }
        std::cout << "end" << std::endl;
    }
    else {
        cout << "no such file" << endl;
    }
}
