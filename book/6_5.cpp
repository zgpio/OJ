#include <iostream>
using namespace std;
// 运动员最佳配对问题

// 堆结点类型
class pref {
public:
    operator int() const { return val; }
    int getbest();

private:
    void init();
    void Compute(int ii);
    int s, val, *r;
};

// 解运动员最佳配对问题的优先队列式分支限界法
void pref::init()
{
    cin >> n;
    s = 0;
    r = new int[n + 1];
    bestr = new int[n + 1];
    Make2DArray(p, n + 1, n + 1);
    Make2DArray(q, n + 1, n + 1);
    for (int i = 1; i <= n; i++) r[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> p[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> q[i][j];
}
void pref::Compute(int ii)
{
    for (int i = 1, temp = 0; i <= ii; i++) temp += p[i][r[i]] * q[r[i]][i];
    val = temp;
}
int pref::getbest()
{
    MaxHeap<pref> H(HeapSize);
    pref E;
    E.init();
    while (true) {
        if (E.s == n - 1) {
            E.Compute(n);
            if (E.val > best) {
                delete[] bestr;
                bestr = E.r;
                best = E.val;
            }
            else
                delete[] E.r;
        }
        else {
            for (int i = E.s + 1; i <= n; i++) {
                pref N;
                N.r = new int[n + 1];
                N.s = E.s + 1;
                N.val = E.val;
                for (int j = 1; j <= n; j++) N.r[j] = E.r[j];
                N.r[N.s] = E.r[i];
                N.r[i] = E.r[N.s];
                N.Compute(N.s);
                H.Insert(N);
            }
            delete[] E.r;
        }
        try {
            H.DeleteMax(E);
        }
        catch (OutOfBounds) {
            return best;
        }
    }
}
