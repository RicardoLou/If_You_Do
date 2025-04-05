#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<ll> v1(n), v2(m);
    for (ll& x : v1) {
        cin >> x;
    }
    for (ll& x : v2) {
        cin >> x;
    }

    for (int i = 0; i < m; i++) {
        ll t = 0;
        for (int j = 0; j < n; j++) {
            if (t >= v2[i]) {
                break;
            }
            if (v1[j] > t) {
                ll d = v1[j];
                v1[j] += min(v2[i] - t, v1[j] - t);
                t = d;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << v1[i] << endl;
    }

}