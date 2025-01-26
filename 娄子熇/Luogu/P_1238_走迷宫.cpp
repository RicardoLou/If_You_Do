#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int N = 20;
int g[N][N];
bool vis[N][N];
int m, n;
int beginX, beginY;
int endX, endY;
vector<pair<int, int> > path;
// 左上右下
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void dfs(int x, int y) {
    if (x == endX && y == endY) {
        // 一条路径可行
        for(int i = 0; i < path.size(); i ++) {
            cout << "(" << path[i].x + 1 << "," << path[i].y + 1 << ")";
            if (i != path.size() - 1)
                cout << "->";
        }
        cout << endl;
    }
    for(int i = 0; i < 4; i ++) {
        int ddx = x + dx[i];
        int ddy = y + dy[i];
        if (ddx >= 0 && ddx < m && ddy >= 0 && ddy < n && !vis[ddx][ddy] && g[ddx][ddy]) {
            vis[ddx][ddy] = true;
            path.push_back(make_pair(ddx, ddy));
            dfs(ddx, ddy);
            path.pop_back();
            vis[ddx][ddy] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for(int i = 0; i < m; i ++) {
        for(int j = 0; j < n; j ++) {
            cin >> g[i][j];
        }
    }
    cin >> beginX >> beginY;
    cin >> endX >> endY;
    beginX --; beginY --; endX--; endY --;
    vis[beginX][beginY] = true;
    path.push_back(make_pair(beginX, beginY));
    dfs(beginX, beginY);
    return 0;
}