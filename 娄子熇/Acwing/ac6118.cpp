#include<bits/stdc++.h>
using namespace std;

const int N = 5 * 1e5;
int a[N], s[N];
int n, t;
int main() {
    cin >> n;
    while(n --) {
        cin >> t;
        // 构造前缀和
        for(int i = 1; i <= t; i ++) {
            int x;
            cin >> x;
            s[i] = s[i - 1] + x;
        }
        long long ans1 = 0, ans2 = 0;
        int i = 1, j = t;
        // cnt + cnt + 2 = t
        // cnt = (t - 2) / 2
        int cnt = (t - 2) / 2;
        for(int k = 0; k <= cnt; k ++) {
            // 枚举埃尔茜吃的数量，前面吃k个，后面吃cnt-k个
            long long sum = s[k] + (s[n] - s[n - cnt + k]);
            if (sum > ans2) {
                ans2 = sum;
            }
        }
        ans1 = s[t] - ans2;
        printf("%Ld %Ld\n", ans1, ans2);
    }
    return 0;
}