#include<bits/stdc++.h>
using namespace std;

const int N = 110;
const int M = 1010;
int t, m;
int a[N][2];
int dp[N][M];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> a[i][0] >> a[i][1];
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = 0; j <= t; j ++) {
            if (j - a[i][0] >= 0) {
                // 不选这个，或者选这个
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i][0]] + a[i][1]);
            } else {
                // 当前这个无法装进去，最大价值保持不变
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[m][t];
}