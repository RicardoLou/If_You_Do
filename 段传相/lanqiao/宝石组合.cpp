#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//能过25%
ll _gcd(ll a, ll b) {
    return b == 0 ? a : _gcd(b, a % b);
}

ll _lcm(ll a, ll b) {
    return a / _gcd(a, b) * b;
}

ll S(ll a, ll b, ll c) {
    return a * b * c * _lcm(_lcm(a, b), c) / (_lcm(a, b) * _lcm(a, c) * _lcm(b, c));
}

int main()
{
    // 请在此输入您的代码
    int n;
    cin >> n;
    vector<ll> v(n);
    for (ll& x : v) {
        cin >> x;
    }
    sort(v.begin(), v.begin() + n);
    map<ll, multiset<ll>> mp;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                ll s = S(v[i], v[j], v[k]);
                mp[s].insert(v[i]);
                mp[s].insert(v[j]);
                mp[s].insert(v[k]);
            }
        }
    }

    auto q = mp.rbegin()->second;
    int cnt = 0;
    for (auto it = q.begin(); it != q.end(); it++) {
        if (cnt >= 3) {
            break;
        }
        if (it == q.begin()) {
            cout << *it;
        }
        else {
            cout << ' ' << *it;
        }
        cnt++;
    }


    return 0;
}