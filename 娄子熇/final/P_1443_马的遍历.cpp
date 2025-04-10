#include <bits/stdc++.h>
using namespace std;

const int N = 410;
int n, m;
int g[N][N];
int dif[8][2] = { {-2, -1}, {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {-1, -2}, {1, -2} }; // 马的偏移

void dfs(int x, int y, int step) {
    if (step > 500) return;
    // 遍历 8 个方向
    for(int i = 0; i < 8; i++) {
        int dx = x + dif[i][0];
        int dy = y + dif[i][1];
        if(dx > 0 && dx <= n && dy > 0 && dy <= m) {
            int nextStep = step + 1;
            if(nextStep < g[dx][dy]) { // 若发现更优的步数，则更新并递归
                g[dx][dy] = nextStep;
                dfs(dx, dy, nextStep);
            }
        }
    }
}

int main() {
    int sx, sy;
    scanf("%d %d %d %d", &n, &m, &sx, &sy);
    memset(g, 0x3f, sizeof(g));
    g[sx][sy] = 0;
    dfs(sx, sy, 0);
    
    // 输出每个位置的最少步数
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(g[i][j] >= 0x3f3f3f3f) {
                int t = -1;
                printf("%-5d", t);
            }
            else
                printf("%-5d", g[i][j]);
        }
        cout << endl;
    }
    return 0;
}
