#include <bits/stdc++.h>
using namespace std;

const int N = 10;
int g[N][N];
int T;
int n, m;
int ans, mx;
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int vis[N][N];

void dfs(int x, int y) {
    if (y == m + 1) {
        dfs(x + 1, 1); // 修复列重置
        return;
    }
    if (x == n + 1) {
        ans = max(ans, mx);
        return;
    }
    // 跳过当前格子
    dfs(x, y + 1);
    // 选取当前格子
    if (!vis[x][y]) {
        mx += g[x][y];
        for (int i = 0; i < 8; i++) {
            int dxx = x + dx[i];
            int dyy = y + dy[i];
            if (dxx >= 1 && dxx <= n && dyy >= 1 && dyy <= m) { // 边界检查
                vis[dxx][dyy] ++;
            }
        }
        dfs(x, y + 1);
        for (int i = 0; i < 8; i++) {
            int dxx = x + dx[i];
            int dyy = y + dy[i];
            if (dxx >= 1 && dxx <= n && dyy >= 1 && dyy <= m) { // 边界检查
                vis[dxx][dyy] --;
            }
        }
        mx -= g[x][y];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    while (T--) {
        memset(g, 0, sizeof(g));
        memset(vis, 0, sizeof(vis));
        ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> g[i][j];
            }
        }
        ans = 0;
        mx = 0;
        dfs(1, 1);
        cout << ans << endl;
    }
    return 0;
}