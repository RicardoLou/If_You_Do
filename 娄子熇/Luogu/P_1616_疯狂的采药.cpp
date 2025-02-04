#include<bits/stdc++.h>
using namespace std;

const int N = 10010;
const int M = 10000010;
long long dp[M];
long long v[N];
long long w[N];
int main() {
    int t, m;
    cin >> t >> m;
    for(int i = 1; i <= m; i ++) {
        cin >> w[i];
        cin >> v[i];
    }
    for(int i = 1; i <= m; i ++) {
        for(int j = w[i]; j <= t; j ++) {
            dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
        }
    }
    cout << dp[t];
    return 0;
}