// 最大团问题的迭代回溯法
#define NoEdge 0

class Clique {
    int MaxClique(int[]);

private:
    void iterClique();
    bool ok(int);
    int **a,     // 图G的邻接矩阵
        n,       // G的顶点数
        *x,      // 当前解
        *bestx,  // 当前最优解
        cn,      // 当前顶点数
        bestn;   // 当前最优解的顶点数
};

void Clique::iterClique()
{
    for (int i = 0; i <= n; i++) x[i] = 0;
    int i = 1;
    while (true) {
        while (i <= n && ok(i)) {
            x[i++] = 1;
            cn++;
        }
        if (i >= n) {
            for (int j = 1; j <= n; j++) bestx[j] = x[j];
            bestn = cn;
        }
        else
            x[i++] = 0;
        while (cn + n - i <= bestn) {
            i--;
            while (i && !x[i]) i--;
            if (i == 0) return;
            x[i++] = 0;
            cn--;
        }
    }
}
// ok 函数用于判断当前顶点是否可以加入当前团
bool Clique::ok(int i)
{
    for (int j = 1; j < i; j++)
        if (x[j] && a[i][j] == NoEdge) return false;
    return true;
}

// MaxClique 作初始化, 并调用迭代回溯法求解
int Clique::MaxClique(int v[])
{
    x = new int[n + 1];
    cn = 0;
    bestn = 0;
    bestx = v;
    iterClique();
    delete[] x;
    return bestn;
}
