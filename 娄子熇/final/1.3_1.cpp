#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < 31; i ++) {
        int cnt1 = 0;
        for(int x : a) {
            if ((x >> i) & 1) cnt1 ++;
        }
        // 当前位共有多少0
        int cnt0 = n - cnt1;
        if ((cnt0 * cnt1) % 2 != 0) {
            // 把当前位插到ans中
            ans |= (1 << i);
        }
    }
    cout << ans;
    return 0;
}