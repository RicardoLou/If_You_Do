#include<bits/stdc++.h>
using namespace std;

const int N = 110;
const int MOD = 1e6 + 7;
int a[N];
int n, m;
int dp[N][N];

int main() {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dp[0][0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = 0; j <= m; j ++) {
            for(int k = 0; k <= min(j, a[i]); k ++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % MOD; // 考虑第 i 种花放 k 盆，剩下的 j - k 盆 由前 i - 1种安排 
            }
        }
    }
    cout << dp[n][m];
    return 0;
}