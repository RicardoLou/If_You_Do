#include<bits/stdc++.h>
using namespace std;

const int N = 1000010;
long long a[N];
int n;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    int cnt = 0; // different num
    unordered_map<long long, long long> cnta;
    unordered_map<long long, long long> cntb;
    for(int i = 0; i < n; i ++) {
        cin >> a[i];
        cnta[a[i]] ++;
        if (cnta[a[i]] == 1) {
            cnt ++;
        }
    }
    
    long long ans = 0;
    for(int i = n - 1; i >= 0; i --) {
        cntb[a[i]] ++;
        cnta[a[i]] --;
        if (cnta[a[i]] == 0) {
            cnt --;
        }
        if (cntb[a[i]] == 2) {
            // 就是我们要找的b
            ans += cnt;
            // 如果这个b还有，说明b左边还有其他b
            if (cnta[a[i]] != 0)
                ans --;
        }
    }
    cout << ans;
    return 0;
}