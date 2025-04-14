#include<bits/stdc++.h>
using namespace std;

const int N = 210;
int lift[N];
int n, a, b;
int ans = 1e9;
bool st[N];

void dfs(int u, int step) {
    if (step >= ans) return;
    if (u <= 0 || u > n) return;
    if (u == b) {
        ans = min(ans, step);
        return;
    }
    st[u] = true;
    if (u - lift[u] >= 1 && !st[u - lift[u]]) {
        dfs(u - lift[u], step + 1);
    }
    if (u + lift[u] <= n && !st[u + lift[u]]) {
        dfs(u + lift[u], step + 1);
    }
    st[u] = false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i ++) {
        cin >> lift[i];
    }
    dfs(a, 0);
    if (ans == 1e9) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}