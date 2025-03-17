#include<bits/stdc++.h>
using namespace std;
const int N = 1010;
int dp[N][N];
int main() {
    string s;
    cin >> s;
    string s2 = s;
    int n = s.length();
    reverse(s2.begin(), s2.end());
    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= n; j ++) {
            if (s[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    cout << n - dp[n][n];
    return 0;
}