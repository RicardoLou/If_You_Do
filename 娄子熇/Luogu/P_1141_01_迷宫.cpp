#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, m;
int g[N][N];
bool vis[N][N];
int ans = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y) {
    vis[x][y] = true;
    ans ++;
    for(int i = 0; i < 4; i ++) {
        int ddx = x + dx[i];
        int ddy = y + dy[i];
        if (ddx >= 0 && ddx < n && ddy >= 0 && ddy < n && !vis[ddx][ddy] && g[ddx][ddy] != g[x][y]) {
            dfs(ddx, ddy);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            g[i][j] = row[j] - '0'; // 将字符转换为整数
        }
    }
    int x, y;
    while(m --) {
        cin >> x >> y;
        memset(vis, false, sizeof(vis));
        x --, y --;
        ans = 0; // dfs中会加上起始点
        dfs(x, y);
        cout << ans << endl;
    }

    return 0;
}