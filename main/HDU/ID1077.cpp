#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
using namespace std;

const int maxn = 303;
const double pi = atan(1.0) * 4;
const double len = 1.0001 * 1.0001;
//基础点和向量运算
struct Point {
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
};
typedef Point Vector;
Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }
Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }
bool operator<(const Point& a, const Point& b)
{
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}
const double eps = 1e-6;
int dcmp(double x)  //判断正负，或者等于0
{
    if (fabs(x) < eps)
        return 0;
    else
        return x < 0 ? -1 : 1;
}
bool operator==(const Point& a, const Point& b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }  //点积
double Length(Vector A) { return sqrt(Dot(A, A)); }               // OA长
double Angle(Vector A, Vector B)
{
    return acos(Dot(A, B) / Length(A) / Length(B));
}  // OA和OB的夹角
double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }  //叉积
double Area2(Point A, Point B, Point C)
{
    return Cross(B - A, C - A);
}  //三角形面积
Vector Rotate(Vector A, double rad)  // rad为弧度，旋转rad度
{
    return Vector(A.x * cos(rad) - A.y * sin(rad),
                  A.x * sin(rad) + A.y * cos(rad));
}
Vector Normal(Vector A)  // A的单位法向量，A不能为零向量
{
    double L = Length(A);
    return Vector(-A.y / L, A.x / L);
}
Point e[maxn];
int ans;
int get_cover_num(Point a, Point b, int n)
{
    Point f1, f2, d1, d2, c;
    c = Point((a.x + b.x) / 2, (a.y + b.y) / 2);
    double L = Length(b - a);
    f1 = Normal(b - a);
    f2 = Normal(a - b);
    //找到圆心
    d1 = c + f1 * sqrt(1.0 - L * L / 4);
    d2 = c + f2 * sqrt(1.0 - L * L / 4);
    int i, num1 = 0, num2 = 0;
    //省略一个圆心判断，可以减少一半的时间
    for (i = 0; i < n; i++) {
        if (dcmp(Dot(d1 - e[i], d1 - e[i]) - len) <= 0) num1++;
        // if(dcmp(Dot(d2-e[i],d2-e[i])-len)<=0)num2++;
    }
    return max(num1, num2);
}
int main()
{
#ifdef LOCAL_JUDGE
    freopen("../../input/1077", "rt", stdin);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        int i, j, k, n;
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%lf%lf", &e[i].x, &e[i].y);
        ans = 1;
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (dcmp(Dot(e[i] - e[j], e[i] - e[j]) - 4.0) > 0) continue;
                ans = max(ans, get_cover_num(e[i], e[j], n));
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
