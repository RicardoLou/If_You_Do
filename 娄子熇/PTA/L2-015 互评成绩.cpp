/*
  @pintia psid=994805046380707840 pid=994805062432309248 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 互评成绩
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805062432309248
*/
// @pintia code=start
#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
int n, k, m;
vector<double> a;
int main() {
    cin >> n >> k >> m;
    for(int i = 0; i < n; i ++) {
        int mn = 1e9, mx = -1;
        long long s = 0;
        for(int j = 0; j < k; j ++) {
            int x;
            cin >> x;
            s += x;
            mn = min(mn, x);
            mx = max(mx, x);
        }
        s = s - mn - mx;
        a.push_back(1.0 * s / (k - 2));
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < m; i ++) {
        if (i != 0)
            cout << " ";
        printf("%.3f", a[n - m + i]);
    }
    return 0;
}
// @pintia code=end