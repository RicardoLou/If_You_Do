#include<bits/stdc++.h>
using namespace std;

const int N = 100010;
int a[N][2];
bool vis[N];
int n, s;
int main() {
    cin >> n >> s;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    int v = 1;
    int ans = 0;
    int flag = 1;
    int cnt = 0; // 判断陷入无限循环
    while(s >= 1 && s <= n) {
        cnt ++;
        if (cnt >= 1e7) break;
        // 炮弹，并且可以击破
        if (a[s][0] == 1 and !vis[s] and a[s][1] <= v) {
            ans ++;
            vis[s] = true;
        }else if (a[s][0] == 0) {
            v += a[s][1];
            flag = -flag;
        }
        s += flag * v;
    }
    cout << ans << endl;
    return 0;
}