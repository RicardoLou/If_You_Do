#include<bits/stdc++.h>
using namespace std;

const int N = 25;
int n, k;
int a[N];
int st[N];
int ans = 0;
bool isp(int x) {
    for(int i = 2; i * i <= x; i ++) {
        if (x < 2) return false;
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}
void dfs(int u, int s, int begin) {
    if (u == k) {
        if (isp(s)) {
            ans ++;
        }
    }
    // 避免不同顺序相同的选择被重复记录
    for(int i = begin; i < n; i ++) {
        dfs(u + 1, s + a[i], i + 1);
    }
}
int main() {
    cin >> n >> k;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    dfs(0, 0, 0);
    cout << ans << endl;
    return 0;
}