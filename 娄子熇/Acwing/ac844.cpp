#include<bits/stdc++.h>
using namespace std;

const int N = 110;
int g[N][N];
int dis[N][N];
int n, m;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, 1, 0};
int bfs() {
    memset(dis, -1, sizeof(dis));
    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));
    dis[0][0] = 0;
    while(!q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        for(int i = 0; i < 4; i ++) {
            int x = t.first + dx[i];
            int y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && !g[x][y] && dis[x][y] == -1) {
                dis[x][y] = dis[t.first][t.second] + 1;
                q.push(make_pair(x, y));
            }
        }
    }
    return dis[n - 1][m - 1];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
    }
    cout << bfs();
    return 0;
}