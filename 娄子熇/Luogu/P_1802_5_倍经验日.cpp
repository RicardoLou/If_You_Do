#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
int n, x;
int info[N][3];
long long dp[N][N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> x;
    for(int i = 1; i <= n; i ++) {
        cin >> info[i][0] >> info[i][1] >> info[i][2];
    }
    for(int i = 1; i <= n; i ++) {
        for(int j = x; j >= 0; j --) {
            if (j - info[i][2] >= 0) {
                dp[i][j] = max(dp[i - 1][j] + info[i][0], dp[i - 1][j - info[i][2]] + info[i][1]);
            } else {
                dp[i][j] = dp[i -  1][j] + info[i][0];
            }
        }
    }
    cout << dp[n][x] * 5;
    return 0;
}