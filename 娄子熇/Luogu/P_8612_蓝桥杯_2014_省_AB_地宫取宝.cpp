#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int N = 60;
int g[N][N];
int n, m, k;
int memo[N][N][N][N];

int dfs(int x, int y, int mx, int cnt) {
    // 边界
    if (x >= n || y >= m) 
        return 0;
    
    // 终点
    if (x == n - 1 && y == m - 1) {
        return (cnt == k || (cnt == k - 1 && g[x][y] > mx)) ? 1 : 0;
    }

    if (memo[x][y][mx + 1][cnt] != -1)
        return memo[x][y][mx + 1][cnt];

    int res = 0;
    
    // 不更新最大值的情况下走
    res = (res + dfs(x + 1, y, mx, cnt)) % MOD;
    res = (res + dfs(x, y + 1, mx, cnt)) % MOD;

    // 如果当前值比之前的最大值大，则更新最大值
    if (g[x][y] > mx) {
        res = (res + dfs(x + 1, y, g[x][y], cnt + 1)) % MOD;
        res = (res + dfs(x, y + 1, g[x][y], cnt + 1)) % MOD;
    }

    return memo[x][y][mx + 1][cnt] = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    memset(memo, -1, sizeof(memo));
    cout << dfs(0, 0, -1, 0) << endl;

    return 0;
}
