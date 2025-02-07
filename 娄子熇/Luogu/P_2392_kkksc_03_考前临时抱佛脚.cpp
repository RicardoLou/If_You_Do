#include<bits/stdc++.h>
using namespace std;

const int N = 65;
int s[5];
int a[5][N];
int l, r;
int mn;
void dfs(int i, int j) {
    if (j > s[i]) {
        mn = min(mn, max(l, r));
        return;
    }
    l += a[i][j];
    dfs(i, j + 1);
    l -= a[i][j];
    r += a[i][j];
    dfs(i, j + 1);
    r -= a[i][j];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans = 0;
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for(int i = 0; i < 4; i ++) {
        l = r = 0;
        mn = INT_MAX;
        for(int j = 0; j < s[i]; j ++) {
            cin >> a[i][j];
        }
        dfs(i, 0);
        ans += mn;
    }
    cout << ans;
    return 0;
}