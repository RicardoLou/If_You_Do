#include<bits/stdc++.h>
using namespace std;

const int N = 210;
int n;
int p[N], rd[N][N], dp[N], a[N];
int ans = 0, pos;

void print(int x) {
    if (p[x]) print(p[x]);
    cout << x << " ";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i ++) {
        for(int j = i + 1; j <= n; j ++) {
            cin >> rd[i][j];
        }
    }
    dp[1] = a[1];
    for(int i = 2; i <= n; i ++) {
        dp[i] = a[i];
        for(int j = i - 1; j >= 1; j --) {
            // 从j转移过来更优
            if (rd[j][i] && dp[i] < dp[j] + a[i]) {
                dp[i] = dp[j] + a[i];
                p[i] = j;
            }
        }
        if (ans < dp[i]) {
            ans = dp[i];
            pos = i;
        }
    }
    print(pos);
    cout << endl << ans;
    return 0;
}