#include<bits/stdc++.h>
using namespace std;

const int N = 100;
int path[N];
bool c[N], dg[N], udg[N]; // 行，正对角线，负对角线
int n;
int ans;
void dfs(int u) {
    if (u == n) {
        ans ++;
        // 一种方案可行
        if (ans <= 3) {
            for(int i = 0; i < n; i ++) {
                cout << path[i] << " ";
            }
        cout << endl;
        }
        return;
    }
    for(int i = 0; i < n; i ++) {
        // 同一行，正对角线和负对角线，这里是找到规律发现对角线会变成一样的
        if (!c[i] && !dg[u - i + n] && !udg[u + i]) {
            path[u] = i + 1;
            c[i] = dg[u - i + n] = udg[u + i] = true;
            dfs(u + 1);
            c[i] = dg[u - i + n] = udg[u + i] = false;            
        }
    }
}
int main() {
    cin >> n;
    ans = 0;
    dfs(0);
    cout << ans;
    return 0;
}