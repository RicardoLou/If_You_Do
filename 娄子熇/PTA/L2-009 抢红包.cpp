/*
  @pintia psid=994805046380707840 pid=994805066890854400 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 抢红包
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805066890854400
*/
// @pintia code=start
#include<bits/stdc++.h>
using namespace std;
struct per {
    int u, p, num;
};
const int N = 10010;
vector<per> a(N);
int n;

bool cmp(per& a, per& b) {
    if (a.p != b.p) return a.p > b.p;
    if (a.num != b.num) return a.num > b.num;
    return a.u < b.u;
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        a[i].u = i;
    }    
    for(int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        int s = 0; // 记录发出去多少红包
        for(int j = 1; j <= k; j ++) {
            int u, p;
            cin >> u >> p;
            s += p;
            a[u] = {u, a[u].p + p, a[u].num + 1};
        }
        a[i].p -= s; // 发出去的红包
    }
    sort(a.begin() + 1, a.begin() + n + 1, cmp);
    for(int i = 1; i <= n; i ++) {
        printf("%d %.2f\n", a[i].u, 1.0 * a[i].p / 100);
    }
    return 0;
}
// @pintia code=end