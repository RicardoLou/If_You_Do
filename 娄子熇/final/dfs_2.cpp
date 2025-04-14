#include<bits/stdc++.h>
using namespace std;

const int N = 15;
int p[N][3];
int T;
int n;
int vis[N];
bool flag;
bool dfs(int time, int cnt) {
    if (cnt == n) {
        flag = true;
        return true;
    }

    for(int i = 0; i < n; i ++) {
        if (!vis[i]) {
            // 对于每架飞机，可以降落的区间是[到达时间，到达时间+盘旋时间]
            int startTime = max(time, p[i][0]);
            // 可以满足
            if (startTime <= p[i][0] + p[i][1]) {
                vis[i] = true;
                dfs(startTime + p[i][2], cnt + 1);
                if (flag) return true;
                vis[i] = false;
            }
        }
    }
    return false;
}


int main() {
    cin >> T;
    while(T --) {
        cin >> n;
        flag = false;
        memset(vis, false, sizeof vis);
        for(int i = 0; i < n; i ++) {
            cin >> p[i][0] >> p[i][1] >> p[i][2];
        }
        if (dfs(0, 0)) {
            cout << "YES" << endl;
        } else cout << "NO" << endl;
    }
    return 0;
}