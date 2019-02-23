#include <iostream>
using namespace std;

// 最小重量机器设计问题
// 算法思想: 启发式搜索, 回溯法, 优先队列由二叉堆维护

// 状态空间树的结点类型
class bbnode {
    friend Mach<int, int>;
    friend int Machine(int **, int **, int, int, int, int *);

private:
    bbnode *parent;
    int mj;
};

// 堆结点类型
template <class Typew, class Typep>
class HeapNode {
    friend Mach<Typew, Typep>;

public:
    operator Typew() const { return weight; }

private:
    Typep profit;
    Typew weight;
    int level;
    bbnode *ptr;
};

// 解最小重量机器设计问题的优先队列式分支限界法
template <class Typew, class Typep>
class Mach {
    friend Typep Machine(Typep **, Typew **, Typew, int, int, int *);

public:
    Typep MinWeightMachine();

private:
    MinHeap<HeapNode<Typep, Typew>> *H;
    void AddLiveNode(Typep cp, Typew cw, int i, int j);
    bbnode *E;
    int n, m, *bestx;
    Typew cc, cw, **w;
    Typep cp, **c;
};

template <class Typew, class Typep>
Typep Mach<Typew, Typep>::MinWeightMachine()
{
    H = new MinHeap<HeapNode<Typep, Typew>>(HeapSize);
    bestx = new int[n + 1];
    int i = 1;
    E = 0;
    cw = cp = 0;
    Typep besTypep = 0;
    while (i != n + 1) {
        for (int j = 1; j <= m; j++) {
            Typew wt = cw + w[i][j];
            Typep ct = cp + c[i][j];
            if (ct <= cc) AddLiveNode(ct, wt, i + 1, j);
        }
        HeapNode<Typep, Typew> N;
        try {
            H->DeleteMin(N);
        }
        catch (...) {
            break;
        }
        E = N.ptr;
        cw = N.weight;
        cp = N.profit;
        i = N.level;
    }
    if (i <= n) return 0;
    for (int j = n; j > 0; j--) {
        bestx[j] = E->mj;
        E = E->parent;
    }
    return cw;
}
void Mach<int, int>::AddLiveNode(int cp, int cw, int i, int j)
{
    bbnode *b = new bbnode;
    b->parent = E;
    b->mj = j;
    HeapNode<Typep, Typew> N;
    N.profit = cp;
    N.weight = cw;
    N.level = i;
    N.ptr = b;
    H->Insert(N);
}
int Machine(int **c, int **w, int cc, int n, int m, int bestx[])
{
    Mach<int, int> K;
    K.c = c;
    K.w = w;
    K.cp = 0;
    K.cw = 0;
    K.cc = cc;
    K.n = n;
    K.m = m;
    K.bestx = bestx;
    int besTypep = K.MinWeightMachine();
    for (int j = 1; j <= n; j++) bestx[j] = K.bestx[j];
    return besTypep;
}
int main()
{
    int cc, n, m, **c, **w, *bestx;
    cin >> n >> m >> cc;
    Make2DArray(c, n + 1, m + 1);
    Make2DArray(w, n + 1, m + 1);
    bestx = new int[n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> c[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cin >> w[i][j];
    int answer = Machine(c, w, cc, n, m, bestx);
    if (answer > 0) {
        cout << answer << endl;
        for (int i = 1; i <= n; i++) cout << bestx[i] << " ";
        cout << endl;
    }
    else
        cout << "No Solution!" << endl;
    return 0;
}
