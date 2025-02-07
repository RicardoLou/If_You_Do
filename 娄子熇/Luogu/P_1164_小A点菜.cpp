#include<bits/stdc++.h>
using namespace std;

const int N = 110;
const int M = 10010;
int a[N];
int dp[M];
int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    dp[0] = 1;
    for(int i = 1; i <= n; i ++) {
        for(int j = m; j >= a[i]; j --) {
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[m];
    return 0;
}