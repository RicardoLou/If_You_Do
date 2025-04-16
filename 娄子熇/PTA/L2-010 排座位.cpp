/*
  @pintia psid=994805046380707840 pid=994805066135879680 compiler=GXX
  ProblemSet: 团体程序设计天梯赛-练习集
  Title: 排座位
  https://pintia.cn/problem-sets/994805046380707840/exam/problems/type/7?problemSetProblemId=994805066135879680
*/
// @pintia code=start
#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int p[N];
int ship[N][N];
int n, m, k;

int find(int x) {
    if (x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void merge(int a, int b) {
    int ta = find(a), tb = find(b);
    if (ta!= tb) {
        p[ta] = tb;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i ++) {
        p[i] = i;
    }
    for(int i = 1; i <= m; i ++) {
        int a, b, c;
        cin >> a >> b >> c;
        ship[a][b] = ship[b][a] = c;
        if (c == 1) merge(a, b);
    }
    while(k --) {
        int a, b;
        cin >> a >> b;
        int ta = find(a), tb = find(b);
        if (ta == tb && ship[a][b] != -1) cout << "No problem" << endl;
        else if (ta != tb && ship[a][b] != -1) cout << "OK" << endl;
        else if (ta == tb && ship[a][b] == -1) cout << "OK but..." << endl;
        else cout << "No way" << endl;
    }
    return 0;
}
// @pintia code=end