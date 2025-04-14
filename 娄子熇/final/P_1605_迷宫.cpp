#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int n, m, t;
char c[N][N];
int sx, sy, fx, fy;
int ans = 0;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y) {
    if (c[fx][fy] == 't')
        return;
    if (x == fx and y == fy) {
        ans ++;
        return;
    }
    for(int i = 0; i < 4; i ++) {
        int ddx = x + dx[i];
        int ddy = y + dy[i];
        if (ddx > 0 && ddx <= n && ddy > 0 && ddy <= m && c[ddx][ddy] == 0) {
            c[ddx][ddy] = 1;
            dfs(ddx, ddy);
            c[ddx][ddy] = 0;
        }
    }
}
int main () {
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    c[sx][sy] = 1;
    while(t --) {
        int x, y;
        cin >> x >> y;
        c[x][y] = 't';
    }
    dfs(sx, sy);
    cout << ans << endl;
    return 0;
}