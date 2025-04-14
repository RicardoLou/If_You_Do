#include<bits/stdc++.h>
using namespace std;

const int N = 25;
int a, b, x, y;
bool st[N][N];
int memo[N][N];
int ans = 1e9;
struct state {
    int hp_a, hp_b, step;
};

void bfs() {
    queue<state> q;
    q.push({a, b, 0});
    while(!q.empty()) {
        auto t = q.front();
        q.pop();
        if (t.hp_a <= 0 && t.hp_b <= 0) {
            cout << t.step << endl;
            return;
        }
        if (t.hp_a < 0) t.hp_a = 0;
        if (t.hp_b < 0) t.hp_b = 0;
        if (st[t.hp_a][t.hp_b]) continue;
        st[t.hp_a][t.hp_b] = true;
        q.push({t.hp_a - x, t.hp_b, t.step + 1});
        q.push({t.hp_a, t.hp_b - x, t.step + 1});
        q.push({t.hp_a - y, t.hp_b - y, t.step + 1});
    }
}
void dfs(int hpa, int hpb, int step) {
    if (hpa <= 0 && hpb <= 0) {
        ans = min(ans, step);
    }
    if (hpa < 0) hpa = 0;
    if (hpb < 0) hpb = 0;

    if (memo[hpa][hpb] != -1 && step >= memo[hpa][hpb]) return;
    memo[hpa][hpb] = step;
    
    dfs(hpa - x, hpb, step + 1);
    dfs(hpa, hpb - x, step + 1);
    dfs(hpa - y, hpb - y, step + 1);
}
int main() {
    cin >> a >> b >> x >> y;
    memset(memo, -1, sizeof memo);
//     bfs();
    dfs(a, b, 0);
    cout << ans << endl;
    return 0;
}