#include<bits/stdc++.h>
using namespace std;

const int N = 200010;
int n;
int dp[N];
int ans = -N;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int a;
    for(int i = 0; i < n; i ++) {
        cin >> a;
        if (i == 0)
            dp[i] = a;
        else dp[i] = max(a, dp[i - 1] + a);
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}