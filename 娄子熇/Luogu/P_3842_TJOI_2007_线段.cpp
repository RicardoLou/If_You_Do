#include<bits/stdc++.h>
using namespace std;

const int N = 20010;
int n;
int s[N][2];
int dp[N][2];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> s[i][0] >> s[i][1];
    }
    dp[1][0] = s[1][1] + s[1][1] - s[1][0] - 1; // 走完了当前行并且最后停在左端点花费的步数
    dp[1][1] = s[1][1] - 1; // 走完了当前行并且最后停在右端点花费的步数

    for(int i = 2; i <= n; i ++) {
        dp[i][0] = min(1 + dp[i - 1][0] + abs(s[i - 1][0] - s[i][1]) + s[i][1] - s[i][0], 1 + dp[i - 1][1] + abs(s[i - 1][1] - s[i][1]) + s[i][1] - s[i][0]);
        dp[i][1] = min(1 + dp[i - 1][0] + abs(s[i - 1][0] - s[i][0]) + s[i][1] - s[i][0], 1 + dp[i - 1][1] + abs(s[i - 1][1] - s[i][0]) + s[i][1] - s[i][0]);
    }
    cout << min(dp[n][0] + (n - s[n][0]), dp[n][1] + (n - s[n][1]));
    return 0;
}