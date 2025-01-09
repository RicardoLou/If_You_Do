#include <bits/stdc++.h>
using namespace std;

const int MAX_M = 10000; // 最大金额
const int MAX_N = 100;   // 最大菜品数

int dp[MAX_M + 1];       // dp 数组，表示凑出金额 j 的方案数

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp[0] = 1; // 初始化：凑出金额 0 有 1 种方法
    for (int i = 0; i < n; i++) { // 枚举每种菜
        for (int j = m; j >= a[i]; j--) { // 从后往前更新
            dp[j] += dp[j - a[i]];
        }
    }

    cout << dp[m] << endl; // 输出凑出金额 m 的方案数

    return 0;
}