#include<bits/stdc++.h>
using namespace std;

const int N = 25;
char g[N][N];
bool st[N][N];
int w, h;
int x, y;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int ans = 1;

void dfs(int x, int y) {
    for(int i = 0; i < 4; i ++) {
        int ddx = x + dx[i];
        int ddy = y + dy[i];
        if (ddx > 0 && ddx <= h && ddy > 0 && ddy <= w && !st[ddx][ddy] && g[ddx][ddy] == '.') {
            ans ++;
            st[ddx][ddy] = true;
            dfs(ddx, ddy);
            // 因为可以重复走，但是不能重复记录，所以不需要回溯
            // st[ddx][ddy] = false;
        }
    }
}
int main() {
    cin >> w >> h;
    for(int i = 1; i <= h; i ++) {
        string s;
        cin >> s;
        for(int j = 1; j <= w; j ++) {
            if (s[j - 1] == '@') {
                x = i;
                y = j;
            }
            g[i][j] = s[j - 1];
        }
    }
    dfs(x, y);
    cout << ans << endl;
    return 0;
}