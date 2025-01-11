#include<bits/stdc++.h>
using namespace std;

const int N = 25;
int g[N][N];
int n;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
int main() {
    ios:: sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            int x;
            cin >> x;
            g[i][j] = x;
        }
    }

    // 对于每个零的四个方向是否存在 1，这样的零一定不会出现在边界
    for(int i = 1; i < n - 1; i ++) {
        for(int j = 1; j < n - 1; j ++) {
            int cnt = 0;
            if (g[i][j] == 0) {
                for(int k = 0; k < 4; k ++) {
                    int x = i + dx[k], y = j + dy[k];
                    while(x >= 0 && x < n && y >= 0 && y < n) {
                        if (g[x][y] == 1) {
                            cnt ++;
                            break;
                        }
                        x += dx[k];
                        y += dy[k];
                    }
                    if (cnt == 4) {
                        g[i][j] = 2;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < n; j ++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}