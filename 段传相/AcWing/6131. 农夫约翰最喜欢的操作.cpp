#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> v(2 * n);
        for (int i = 0; i < n; i++) {
            ll x;
            cin >> x;
            v[i] = x % m;
        }
        sort(v.begin(), v.begin() + n);
        for (int i = 0; i < n; i++) {
            v[i + n] = v[i] + m;
        }
        vector<ll> pre(2 * n + 1);
        for (int i = 1; i <= 2 * n; i++) {
            pre[i] = pre[i - 1] + v[i - 1];
        }
        ll ans = 1e18;
        for (int i = 1; i <= n; i++) {
            int l = i, r = i + n - 1;
            int mid = (l + r + 1) / 2;
            ll res;
            //从中位数（应该是上取整的中位数）到最后的数累加起来减去中位数之前的累加，得到的就是操作次数
            if (n % 2 == 0) {//偶数长度
                res = pre[r] - pre[mid - 1] - pre[mid - 1] + pre[l - 1];
            }
            else {//奇数长度
                res = pre[r] - pre[mid] - pre[mid - 1] + pre[l - 1];
            }
            ans = min(res, ans);
        }
        cout << ans << endl;
        v.clear();
        pre.clear();
    }

}
