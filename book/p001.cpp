#include <fstream>
#include <iostream>
#include <queue>
using namespace std;

template <class T>
using MaxHeap = priority_queue<T>;
// TODO: 抽象为模板类, 但是参照书上出现友元私有成员访问的问题
class HeapNode;

class bbnode {
    friend void AddLiveNode(MaxHeap<HeapNode> &, bbnode *, int, bool, int);
    friend int MaxLoading(int *, int, int, int *);
    friend class AdjacencyGraph;

private:
    bbnode *parent;
    bool LChild;
};
class HeapNode {
    friend void AddLiveNode(MaxHeap<HeapNode> &, bbnode *, int, bool,
                            int);
    friend int MaxLoading(int *, int, int, int *);

public:
    operator int() const { return uweight; }

private:
    bbnode *ptr;
    int uweight;
    int level;
};

void AddLiveNode(MaxHeap<HeapNode> &H, bbnode *E, int wt, bool ch,
                 int lev)
{
    bbnode *b = new bbnode;
    b->parent = E;
    b->LChild = ch;
    HeapNode N;
    N.uweight = wt;
    N.level = lev;
    N.ptr = b;
    H.push(N);
}
int MaxLoading(int w[], int c, int n, int bestx[])
{
    MaxHeap<HeapNode> H;
    int *r = new int[n + 1];
    r[n] = 0;
    for (int j = n - 1; j > 0; j--) r[j] = r[j + 1] + w[j + 1];
    int i = 1;
    bbnode *E = 0;
    int Ew = 0;
    while (i != n + 1) {
        if (Ew + w[i] <= c) AddLiveNode(H, E, Ew + w[i] + r[i], true, i + 1);
        AddLiveNode(H, E, Ew + r[i], false, i + 1);
        HeapNode N;
        // H.pop();
        i = N.level;
        E = N.ptr;
        Ew = N.uweight - r[i - 1];
    }
    for (int j = n; j > 0; j--) {
        bestx[j] = E->LChild;
        E = E->parent;
    }
    return Ew;
}

int main(int argc, char *argv[])
{
    ifstream cin;
    cin.open("./input/p001", ios::in);
    int n, c;
    cin >> n >> c;
    int w[n + 1];
    int bestx[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }
    std::cout << n << " " << c << std::endl;
    for (int i = 1; i <= n; ++i) {
        std::cout << w[i] << " ";
    }
    std::cout << std::endl;
    std::cout << MaxLoading(w, c, n, bestx) << std::endl;
    return 0;
}
