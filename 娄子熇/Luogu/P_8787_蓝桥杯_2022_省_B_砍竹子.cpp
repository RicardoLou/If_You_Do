#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
long long h[N], cnt[N];
int main() {
    int n;
    cin >> n;
    long long mx = -1;
    for(int i = 0; i < n; i ++) {
        cin >> h[i];
        long long temp = h[i];
        // 最后减到1
        while(temp - 1) {
            cnt[i] ++;
            temp = sqrtl(temp / 2 + 1);
        }
        mx = max(mx, cnt[i]); // 找最大的砍伐的次数
    }
    long long ans = 0;
    for(int i = mx; i > 0; i --) {
        for(int j = 0; j < n; j ++) {
            if (cnt[j] == i) {
                if (h[j] != h[j + 1]) {
                    ans ++;
                }
                cnt[j] --;
                h[j] = sqrtl(h[j] / 2 + 1);
            }
        }
    }
    cout << ans;
    return 0;
}