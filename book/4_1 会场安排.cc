#include <algorithm>  // std::sort
#include <fstream>
#include <iostream>
// #include <sstream>
using namespace std;

struct Job {
    int begin, end;
    bool ok;
};

// note: '<'是期望的顺序
bool jobComp(Job &i, Job &j)
{
    return (i.end < j.end);
}
// 贪心策略:
// 1) 按会议开始的顺序升序
// 2) 遍历所有会议, 找出可以安排在一个会场的会议(即会议不会出现重合), 就划分到一个会场中
// 3) 重复2)步骤直到所有会议安排完成
// 4) 最后一共有多少个集合就要有多少个会场.
// 第一次会将安排在第一个会场的所有会议划分为一个集合, 第二次安排第二个会场, ... 直到安排完所有的会议.
// 这里使用ok来过滤已安排的会议.
int manage(int n, Job *b)
{
    sort(b, b + n, jobComp);                    // [b, b+n)
    int count = n, roomavail = 0, roomnum = 0;  // count表示还剩余几个活动未安排
    while (count > 0) {                         // 当count=0就退出while循环
        for (int i = 0; i < n; ++i) {
            // 如果当前活动未安排并且和会场中已有活动不冲突
            if ((b[i].begin > roomavail) && (!b[i].ok)) {
                // 将当前活动加入该会场, 并且更新会场的空闲时间
                roomavail = b[i].end;
                b[i].ok = 1;  // 标记该活动已被安排
                count--;      // 未安排的活动数减1
            }
        }
        roomavail = 0;  // 把roomavail初始化, 相当于重新再找一个房间
        roomnum++;      // 遍历一次, 使用的会场数加1
    }
    return roomnum;  // 返回使用的会场数
}

// 更优的策略:
// 将会议开始时间和结束时间都排序, 这时候会议的开始时间和结束时间都是升序的.
// 遍历会议的开始时间, 如果有会议i的开始时间小于某会议j的结束时间, 那么该会议i一定是需要开辟一个新会场的,
// 而当会议i开始时间大于某会议j的结束时间, 该会议i可以利用之前的会场, 而不需要开辟新的会场.

int manage2()
{
    int n;
    cin >> n;
    int s[10010];  // 会议开始时间
    int e[10010];  // 会议终止时间
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> e[i];
    }
    sort(s, s + n);
    sort(e, e + n);
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < e[j]) {
            cnt++;
        } else {
            j++;
        }
    }
    return cnt;
}

int main()
{
    ifstream cin;
    cin.open("./input/4_1", ios::in);
    int n;
    cin >> n;  // job个数
    Job b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i].begin >> b[i].end;
        b[i].ok = 0;
    }
    cin.close();
    int roomnum = manage(n, b);

    // ofstream outfile;
    // outfile.open("output.txt", ios::out);
    // outfile << roomnum << endl;
    // outfile.close();
    cout << roomnum << endl;
    return 0;
}
